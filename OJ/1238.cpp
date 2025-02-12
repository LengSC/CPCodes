#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    namespace IO {
        template<typename T>
        void read(T &x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    constexpr int N = 2050;

    int n, m;

    namespace BIT {
        ll t1[N][N], t2[N][N], t3[N][N], t4[N][N];

        void add(ll x, ll y, ll v) {
            for (int i = x; i <= n; i += i & -i)
                for (int j = y; j <= m; j += j & -j) {
                    t1[i][j] += v;
                    t2[i][j] += v * x;
                    t3[i][j] += v * y;
                    t4[i][j] += v * x * y;
                }
        }

        void add(ll xa, ll ya, ll xb, ll yb, ll v) {
            add(xa, ya, v);
            add(xa, yb + 1, -v);
            add(xb + 1, ya, -v);
            add(xb + 1, yb + 1, v);
        }

        ll qry(ll x, ll y) {
            ll res = 0;
            for (int i = x; i; i ^= i & -i)
                for (int j = y; j; j ^= j & -j)
                    res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
            return res;
        }

        ll qry(ll xa, ll ya, ll xb, ll yb) {
            return qry(xb, yb) - qry(xb, ya - 1) - qry(xa - 1, yb) + qry(xa - 1, ya - 1);
        }
    }

    int op, xa, ya, xb, yb, v;

    int main() {
        read(n, m);
        while (~scanf("%d", &op)) {
            if (op == 1) {
                read(xa, ya, xb, yb, v);
                BIT::add(xa, ya, xb, yb, v);
            } else {
                read(xa, ya, xb, yb);
                printf("%lld\n", BIT::qry(xa, ya, xb, yb));
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }

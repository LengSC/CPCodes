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

    constexpr int N = 200001;

    ll m, n, a[4][N], c[N * 2], tot;
    ll ans;

    struct Q {
        ll op, x, y, val;
        bool operator<(const Q &b) const {
            if (x != b.x) return x < b.x;
            return op < b.op;
        }
    } q[N * 2];

    void add(ll x) { for (; x < N * 2; x += x & -x) ++c[x]; }

    ll qry(ll x) {
        ll res = 0;
        for (; x; x ^= x & -x) res += c[x];
        return res;
    }

    ll calc(ll x, ll y, ll z) {
        ll res = 0;
        memset(c, 0, sizeof(c)); tot = 0;
        rep(i, 1, n)
            q[++tot] = {0, a[x][i] - a[y][i] + (x > y), a[y][i] - a[z][i] + (y > z), 0},
            q[++tot] = {1, a[y][i] - a[x][i], a[z][i] - a[y][i], a[y][i]};
        sort(q + 1, q + tot + 1);
        rep(i, 1, tot)
            if (q[i].op == 0) add(q[i].y + N);
            else res += q[i].val * qry(q[i].y + N);
        return res;
    }

    int main() {
        read(m, n);
        dep(i, 0, m) rep(j, 1, n) read(a[i][j]);
        rep(i, m, 3) rep(j, 1, n) a[i][j] = a[i - m][j];
        rep(i, 0, 3) rep(j, 1, n) ans += a[i][j] * n * 2;
        rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) if (i != j && j != k && k != i) ans -= calc(i, j, k);
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

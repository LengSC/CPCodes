#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
    #define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)
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

    constexpr int N = 5e4 + 2, MOD = 998244353;

    int t, op;

    int n, a[N], b[N], ans, fac;
    ll rk;

    namespace BIT {
        int c[N];

        void add(int x) {
            for (; x <= n; x += x & -x) (++c[x]) %= MOD; // but no need to mod
        }

        int query(int x) {
            int res = 0;
            for (; x; x ^= x & -x) (res += c[x]) %= MOD;
            return res;
        }
    }

    namespace SGT {
        #define lc (cur << 1)
        #define rc (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        int tr[N << 2];

        void build(int cur, int l, int r) {
            if (l == r) return tr[cur] = 1, void();
            build(lc, l, mid), build(rc, mid + 1, r);
            tr[cur] = tr[lc] + tr[rc];
        }

        int query(int cur, int l, int r, int x) {
            --tr[cur];
            if (l == r) return l;
            return (tr[lc] >= x) ? query(lc, l, mid, x) : query(rc, mid + 1, r, x - tr[lc]);
        }
    }

    void getRank() {
        read(n);
        rep(i, 1, n) read(a[i]);
        memset(BIT::c, 0, sizeof(int) * (n + 1));
        per(i, n, 1) b[i] = BIT::query(a[i] - 1), BIT::add(a[i]);
        ans = fac = 1;
        per(i, n, 1)
            ans = (ans + (ll)b[i] * fac) % MOD,
            fac = (ll)fac * (n - i + 1) % MOD;
        printf("%d\n", ans);
    }

    void getPerm() {
        read(n, rk);
        SGT::build(1, 1, n);
        --rk;
        rep(i, 1, n) b[n - i] = rk % i, rk /= i;
        rep(i, 0, n - 1) a[i] = SGT::query(1, 1, n, b[i] + 1);
        rep(i, 0, n - 1) printf("%d ", a[i]);
        puts("");
    }

    int main() {
        for (read(t); t; --t) read(op), op ? getPerm() : getRank();
        return 0;
    }
}

int main() { return SLV::main(); }
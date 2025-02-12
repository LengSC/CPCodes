#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
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

    constexpr int N = 2002, MOD = 1e9 + 7;

    int n, a[N], b[N], f[N][N], c[N][N], tot, fac[N], ans;

    void add(int x, int y, int v) {
        for (; y <= n; y += y & -y) c[x][y] = (c[x][y] + v) % MOD;
    }

    int qry(int x, int y) {
        int res = 0;
        for (; y; y ^= y & -y) res = (res + c[x][y]) % MOD;
        return res;
    }

    int main() {
        read(n);
        rep(i, 1, n) read(a[i]), b[i] = a[i];
        sort(b + 1, b + 1 + n);
        tot = unique(b + 1, b + 1 + n) - b - 1;
        rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
        fac[0] = 1;
        rep(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
        f[0][0] = 1; // f[i][j]: end of a[i], len=j
        rep(i, 1, n) per(j, i, 1) {
            f[i][j] = qry(j - 1, a[i]) + (j == 1);
            add(j, a[i], f[i][j]);
        }

        rep(i, 0, n) rep(j, 0, n) {
            ans = (ans + (ll)f[i][j] * fac[n - j] % MOD) % MOD;
            ans = (ans - (ll)f[i][j] * fac[n - j] % MOD * j % MOD) % MOD;
        }
        printf("%d\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

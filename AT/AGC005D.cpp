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

    constexpr int N = 2005, MOD = 924844033;

    int n, k, fac[N], f[N * 2][N][2], tot, ans;
    bool notroot[N * 2];

    int main() {
        read(n, k);
        fac[0] = 1;
        rep(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
        rep(i, 1, k)
            rep(t, 0, 1)
                for (int j = i; j <= n; j += k)
                    notroot[++tot] = (i != j);
        f[0][0][0] = 1;
        rep(i, 1, n * 2) rep(j, 0, n) {
            f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
            if (notroot[i] && j) f[i][j][1] = f[i - 1][j - 1][0];
        }
        rep(i, 0, n)
            ans = (ans + (ll)((i & 1) ? -1 : 1) * (f[n * 2][i][0] + f[n * 2][i][1]) * fac[n - i]) % MOD;
        printf("%d\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

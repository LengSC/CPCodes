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

    constexpr int N = 20, M = (1 << 16) + 5, MOD = 1e9 + 7;

    ll n, m, fac[M], inv[M], a[N], lim, ans, dp[N][M];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    void pre() {
        lim = 1 << n, fac[0] = 1;
        rep(i, 1, lim) fac[i] = fac[i - 1] * i % MOD;
        inv[lim] = fpow(fac[lim], MOD - 2);
        per(i, lim, 1) inv[i - 1] = inv[i] * i % MOD;
    }

    ll comb(ll a, ll b) {
        return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    int main() {
        read(n, m);
        rep(i, 1, m) read(a[i]);
        pre();
        sort(a + 1, a + 1 + m, greater<ll>());

        dp[0][0] = 1;
        /* dp[i][j]: consider a[m - i + 1] to a[m], j is the status that is binary-indexed */
        rep(i, 1, m) rep(j, 0, lim - 1) {
            rep(k, 0, n - 1) if (~j >> k & 1) /* i.e. '!((j >> k) & 1)' */
                dp[i][j | (1 << k)] = (dp[i][j | (1 << k)] + dp[i - 1][j] * comb(lim - a[i] - j, (1 << k) - 1) % MOD * fac[1 << k]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
        
        rep(i, 0, lim - 1)
            ans = (ans + ((__builtin_popcount(i) & 1) ? -1 : 1) * dp[m][i] * fac[lim - 1 - i]) % MOD;
        printf("%lld\n", (ans * lim % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

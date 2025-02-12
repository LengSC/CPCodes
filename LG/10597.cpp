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

    constexpr int N = 2005, MOD = 1e9 + 9;

    int n, a, cnt[N];
    ll fac[N], inv[N], f[N][N], ans;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll perm(ll n, ll m) { return fac[n] * inv[n - m] % MOD; }

    ll comb(ll n, ll m) { return fac[n] * inv[n - m] % MOD * inv[m] % MOD; }

    int main() {
        read(n);
        rep(i, 1, n) read(a), ++cnt[a];
        fac[0] = 1;
        rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n], MOD - 2);
        per(i, n, 1) inv[i - 1] = inv[i] * i % MOD;
        f[0][0] = 1;
        rep(i, 1, n) rep(j, 0, n) rep(k, 0, min(j, cnt[i]))
            f[i][j] = (f[i][j] + f[i - 1][j - k] * comb(cnt[i], k) % MOD * perm(cnt[i], k)) % MOD;
        rep(i, 0, n) ans = (ans + (i & 1 ? -1 : 1) * f[n][i] * fac[n - i]) % MOD;
        rep(i, 1, n) ans = ans * inv[cnt[i]] % MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

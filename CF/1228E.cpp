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

    constexpr int N = 255, MOD = 1e9 + 7;

    ll n, k, fac[N], inv[N], ans, sign = 1;

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll comb(ll a, ll b) {
        return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    /**
     * Ans = \sum \limits_{i = 0}^{n} {(-1)^{i} \binom{n}{i}(k^{n - i}(k - 1)^{i} -  (k - 1)^{n})^{n}}
     */

    int main() {
        read(n, k);
        fac[0] = 1; rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n]); per(i, n, 1) inv[i - 1] = inv[i] * i % MOD;
        rep(i, 0, n)
            (ans += sign * comb(n, i) * fpow(fpow(k, n - i) * fpow(k - 1, i) % MOD - fpow(k - 1, n), n)) %= MOD, sign = -sign;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

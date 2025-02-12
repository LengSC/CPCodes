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

    constexpr int M = 1e6 + 5, MOD = 1e9 + 7;

    ll n, m, ans, fac[M], inv[M];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll comb(ll a, ll b) {
        return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    /**
     * Ans = \sum \limits_{k = 0}^{m}(-1)^{k} \cdot (m - k)^{n} \cdot \binom{m + 1}{k + 1}
     */

    int main() {
        read(n, m);
        fac[0] = 1;
        rep(i, 1, m + 1) fac[i] = fac[i - 1] * i % MOD;
        inv[m + 1] = fpow(fac[m + 1], MOD - 2);
        per(i, m + 1, 1) inv[i - 1] = inv[i] * i % MOD;
        rep(k, 0, m - 1)
            ans = (ans + fpow(m - k, n) % MOD * comb(m + 1, k + 1) * (k & 1 ? -1 : 1)) % MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 1e6 + 5, MOD = 998244353;

    ll n, fac[N], inv[N], part1, part2, sign = 1;

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll comb(ll a, ll b) { return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD; }

    int main() {
        read(n);
        fac[0] = 1; rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n]); per(i, n, 1) inv[i - 1] = inv[i] * i % MOD;
        rep(i, 1, n)
            (part1 += sign * comb(n, i) * fpow(3, n * (n - i) + i) % MOD) %= MOD,
            sign = -sign,
            (part2 += sign * comb(n, i) * fpow(fpow(3, n * i)) % MOD * (fpow(1 - fpow(fpow(3, n - i)), n) - 1) % MOD) %= MOD;
        printf("%lld\n", ((part1 * 2 % MOD - part2 * fpow(3, n * n + 1)) % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

/**
 * Ans = 2 \cdot \sum \limits_{i=1}^{n}{\binom{n}{i}(-1)^{i+1} \cdot 3^{n(n-i)+i}}
 *     - 3^{n^2+1} \cdot \sum \limits_{i=1}^{n}{\binom{n}{i}(-1)^{i} \cdot 3^{-ni} ((1-3^{i-n})^n-1)}
 */

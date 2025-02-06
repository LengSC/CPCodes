#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    using uint = unsigned int;
    using ll = long long;
    using ull = unsigned long long;
    using vi = vector<int>;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 500001, M = 21, MOD = 1000000007;

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll n, k, f[N], g[N], fac, c[M], b[N], tmp[N], cnt;
    char s[N << 1];
    /**
     * b[i]: I^k(i)
     * c[i] = comb(i + k - 1, i)
     */

    int main() {
        read(n);
        scanf("%s", s + 1); rep(i, 1, strlen(s + 1)) ((k *= 10) += s[i] -'0') %= MOD;
        rep(i, 1, n) read(f[i]);
        fac = 1; dep(i, 1, M) (fac *= i) %= MOD;
        c[M - 1] = fpow(fac); per(i, M - 1, 1) c[i - 1] = c[i] * i % MOD;
        dep(i, 0, M) dep(j, 0, i) (c[i] *= i + k - 1 - j) %= MOD;
        rep(i, 1, n) b[i] = 1, tmp[i] = i;
        rep(i, 2, n) if (tmp[i] ^ 1)
            for (int j = i; j <= n; (b[j] *= c[cnt]) %= MOD, j += i)
                for (cnt = 0; !(tmp[j] % i); ++cnt, tmp[j] /= i);
        rep(i, 1, n) rep(j, 1, n / i) /* g = f * I^k */
            (g[i * j] += f[i] * b[j] % MOD) %= MOD;
        rep(i, 1, n) printf("%d ", g[i]);
        return 0;
    }
}

int main() { return SLV::main(); }

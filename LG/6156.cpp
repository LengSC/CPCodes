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

    constexpr int N = 1e7 + 5, MOD = 998244353;

    ll n, k, ans, f[N], g[N];
    bitset<N> np;
    vi pr;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    void pre(ll lim) {
        f[1] = g[1] = 1;
        rep(i, 2, lim) {
            if (!np[i]) pr.eb(i), f[i] = i - 1, g[i] = fpow(i, k);
            for (const auto &j: pr) {
                if (i * j > lim) break;
                np[i * j] = true;
                g[i * j] = (g[i] * g[j]) % MOD;
                if (i % j) f[i * j] = (f[i] * f[j]) % MOD;
                else {
                    ll q = i / j;
                    if (q % j) f[i * j] = (-j * f[q]) % MOD;
                    break;
                }
            }
        }
        rep(i, 2, lim) f[i] = (f[i - 1] + f[i] * g[i]) % MOD, (g[i] += g[i - 1]) %= MOD;
        rep(i, 2, lim) (g[i] += g[i - 1]) %= MOD;
    }

    int main() {
        read(n, k);
        pre(n * 2);
        for (int l = 1, r; l <= n; l = r + 1)
            r = n / (n / l),
            (ans += (f[r] - f[l - 1]) * (g[n / l * 2] - g[n / l] * 2)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

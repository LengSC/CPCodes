#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 5e6 + 5, M = 3.5e5, MOD = 1e9 + 7;

    ll T, k, n, m, f[N], pr[M], tot, pw[M], ans;
    bitset<N> np;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    void pre() {
        f[1] = 1;
        dep(i, 2, N) {
            if (!np[i])
                pr[++tot] = i,
                pw[tot] = fpow(i, k),
                f[i] = pw[tot] - 1;
            for (int j = 1; j <= tot && i * pr[j] < N; ++j) {
                np[i * pr[j]] = true;
                if (i % pr[j] == 0) {
                    f[i * pr[j]] = f[i] * pw[j] % MOD;
                    break;
                }
                f[i * pr[j]] = f[i] * f[pr[j]] % MOD;
            }
        }
        dep(i, 2, N) (f[i] += f[i - 1]) %= MOD;
    }

    void solve() {
        read(n, m); ans = 0;
        if (n > m) swap(n, m);
        for (int l = 1, r; l <= n; l = r + 1)
            r = min(n / (n / l), m / (m / l)),
            (ans += (f[r] - f[l - 1]) * (n / l) % MOD * (m / l)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
    }

    int main() {
        for (read(T, k), pre(); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

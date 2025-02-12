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

    constexpr int N = 1e7, MOD = 1e8 + 9;

    ll t, n, m, p, f[N + 2], ans, l, r, x, y;
    bitset<N + 2> np;
    vi pr;

    void pre() {
        f[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), f[i] = 1 - i;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) f[p] = f[i] * f[j];
                else { f[p] = f[i]; break; }
            }
        }
        rep(i, 2, N) f[i] = (f[i - 1] + f[i] * i) % MOD;
    }

    ll s(ll n, ll m) {
        return (n * (n + 1) / 2 % MOD) * (m * (m + 1) / 2 % MOD) % MOD;
    }

    void solve() {
        read(n, m); ans = 0;
        if (n > m) swap(n, m);
        for (l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            (ans += (f[r] - f[l - 1]) * s(x, y)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
    }

    int main() {
        for (pre(), read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

/*
$$
\begin{aligned}
s(n) &= \frac{n(n + 1)}{2}\\

Ans &= \sum \limits_{d = 1}^{n} {s([\frac{n}{d}]) s([\frac{m}{d}]) d \sum \limits_{x \mid d} {x \mu(x)}}
\end{aligned}
$$
*/

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

    constexpr int N = 5e4, MOD = 1e9 + 7;

    ll t, n, m, x1, y1, x2, y2, phi[N + 2], p;
    bitset<N + 2> np;
    vi pr;

    void pre() {
        phi[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), phi[i] = i - 1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) phi[p] = phi[i] * phi[j] % MOD;
                else { phi[p] = phi[i] * j % MOD; break; }
            }
        }
        rep(i, 2, N) (phi[i] += phi[i - 1]) %= MOD;
    }

    ll f(ll n, ll m) {
        ll res = 0, l, r, x, y;
        if (n > m) swap(n, m);
        for (l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            (res += (phi[r] - phi[l - 1]) * x * y) %= MOD;
        return res;
    }

    void solve() {
        read(x1, y1, x2, y2);
        printf("%lld\n", ((f(x2, y2) - f(x1 - 1, y2) - f(x2, y1 - 1) + f(x1 - 1, y1 - 1)) % MOD + MOD) % MOD);
    }

    int main() {
        for (pre(), read(t, n, m); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

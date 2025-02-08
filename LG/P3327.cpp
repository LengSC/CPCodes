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

    constexpr int N = 5e4;

    ll t, n, m, mu[N + 2], f[N + 2], p, l, r, x, y, ans;
    bitset<N + 2> np;
    vi pr;

    void pre() {
        mu[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), mu[i] = -1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) mu[p] = -mu[i];
                else break;
            }
        }
        rep(i, 2, N) mu[i] += mu[i - 1];
        rep(i, 1, N) for (l = 1; l <= i; l = r + 1)
            r = (i / (x = i / l)),
            f[i] += (r - l + 1) * x;
    }

    void solve() {
        read(n, m);
        if (n > m) swap(n, m);
        for (ans = 0, l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            ans += (mu[r] - mu[l - 1]) * f[x] * f[y];
        printf("%lld\n", ans);
    }

    int main() {
        for (pre(), read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

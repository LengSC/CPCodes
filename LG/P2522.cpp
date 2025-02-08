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

    int t, a, b, c, d, k, mu[N + 2], f[N + 2], p;
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
    }

    ll calc(ll n, ll m) {
        ll res = 0;
        if (n > m) swap(n, m);
        n /= k, m /= k;
        for (int l = 1, r, x, y; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            res += (ll)(mu[r] - mu[l - 1]) * x * y;
        return res;
    }

    void solve() {
        read(a, b, c, d, k);
        printf("%lld\n", calc(b, d) - calc(a - 1, d) - calc(b, c - 1) + calc(a - 1, c - 1));
    }

    int main() {
        for (pre(), read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

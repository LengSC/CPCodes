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

    constexpr int N = 4e7;

    int t;
    ull n, phi[N + 2], p;
    bitset<N + 2> np;
    vi pr;
    unordered_map<ull, ull> mp;

    void pre() {
        phi[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), phi[i] = i - 1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) phi[p] = phi[i] * phi[j];
                else { phi[p] = phi[i] * j; break; }
            }
        }
        rep(i, 2, N) phi[i] += phi[i - 1];
    }

    ll f(ll n) { return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1); }

    ll sPhi(ll n) {
        if (n <= N) return phi[n];
        if (mp[n]) return mp[n];
        ll res = f(n);
        for (ll l = 2, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            res -= (r - l + 1) * sPhi(x);
        return mp[n] = res;
    }

    void solve() {
        read(n);
        ll ans = 0;
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            ans += (f(r) - f(l - 1)) * (sPhi(x) - 1);
        printf("%llu\n", ans);
    }

    int main() {
        for (pre(), read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

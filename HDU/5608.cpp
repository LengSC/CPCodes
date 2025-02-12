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

    constexpr int N = 1e6, MOD = 1e9 + 7, INV6 = 166666668;

    ll n, p, mu[N + 2], t, ans;
    bitset<N + 2> np;
    vi pr;
    unordered_map<ll, ll> mp;

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

    ll sg(ll n) {
        return (
            n * (n + 1) % MOD * (n * 2 + 1) % MOD * INV6 % MOD -
            n * (n + 1) / 2 % MOD * 3 +
            n * 2
        ) % MOD;
    }

    ll sMu(ll n) {
        if (n <= N) return mu[n];
        if (mp[n]) return mp[n];
        ll res = 1;
        for (ll l = 2, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (r - l + 1) * sMu(x)) %= MOD;
        return mp[n] = res;
    }

    void solve() {
        read(n); ans = 0;
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (ans += (sMu(r) - sMu(l - 1)) * sg(x)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
    }

    int main() {
        for (pre(), read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

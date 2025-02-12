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

    constexpr int N = 1e6, MOD = 1e9 + 7;

    ll n, p, ans, mu[N + 2];
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

    ll sMu(ll n) {
        if (n <= N) return mu[n];
        if (mp[n]) return mp[n];
        ll res = 1, l, r, x;
        for (l = 2; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (r - l + 1) * sMu(x)) %= MOD;
        return mp[n] = res;
    }

    ll g(ll n) {
        ll res = 0, l, r, x;
        for (l = 1; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res += (r - l + 1) * x) %= MOD;
        return res * res % MOD;
    }

    int main() {
        pre();
        read(n);
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (ans += (sMu(r) - sMu(l - 1)) * g(x)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

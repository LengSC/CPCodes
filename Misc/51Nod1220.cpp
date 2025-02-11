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

    ll n, p, mu[N + 2], sigma[N + 2], ans;
    bitset<N + 2> np;
    vi pr;
    unordered_map<ll, ll> mp;

    void pre() {
        mu[1] = sigma[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), mu[i] = -1, sigma[i] = i + 1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) mu[p] = -mu[i], sigma[p] = sigma[i] * sigma[j] % MOD;
                else {
                    sigma[p] = ((sigma[i] - sigma[i / j]) * j + sigma[i]) % MOD;
                    break;
                }
            }
        }
        rep(i, 2, N)
            mu[i] = (mu[i - 1] + mu[i] * i) % MOD,
            (sigma[i] += sigma[i - 1]) %= MOD;
    }

    ll sf(ll n) {
        if (n <= N) return mu[n];
        if (mp[n]) return mp[n];
        ll res = 1;
        for (ll l = 2, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (l + r) * (r - l + 1) / 2 % MOD * sf(x)) %= MOD;
        return mp[n] = res;
    }

    ll sg2(ll n) {
        if (n <= N) return sigma[n] * sigma[n] % MOD;
        ll res = 0;
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res += (l + r) * (r - l + 1) / 2 % MOD * x) %= MOD;
        return res * res % MOD;
    }

    int main() {
        pre();
        read(n);
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (ans += (sf(r) - sf(l - 1)) * sg2(x)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    ll n, p, ans, f[N + 2];
    bitset<N + 2> np;
    vi pr;
    unordered_map<ll, ll> mp;

    void pre() {
        f[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), f[i] = -1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) f[p] = -f[i];
                else break;
            }
        }
        rep(i, 2, N) f[i] = (f[i - 1] + f[i] * i) % MOD;
    }

    ll sf(ll n) {
        if (n <= N) return f[n];
        if (mp[n]) return mp[n];
        ll res = 1, l, r, x;
        for (l = 2; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (l + r) * (r - l + 1) / 2 % MOD * sf(x)) %= MOD;
        return mp[n] = res;
    }

    int main() {
        pre();
        read(n);
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (ans += (sf(r) - sf(l - 1)) * x) %= MOD;
        printf("%lld\n", ans * ans % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

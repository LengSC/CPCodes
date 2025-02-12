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

    constexpr int N = 1e6, MOD = 1e9 + 7, INV2 = 500000004, INV6 = 166666668;

    ll n, p, phi[N + 2], a, b;
    bitset<N + 2> np;
    vi pr;
    unordered_map<ll, ll> mp;

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
        rep(i, 2, N) phi[i] = (phi[i - 1] + phi[i] * i) % MOD;
    }

    ll sg(ll n) {
        if (n <= N) return phi[n];
        if (mp[n]) return mp[n];
        ll res = n * (n + 1) % MOD * (n * 2 + 1) % MOD * INV6 % MOD;
        for (ll l = 2, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (l + r) * (r - l + 1) % MOD * INV2 % MOD * sg(x)) %= MOD;
        return mp[n] = res;
    }

    ll sf(ll n) {
        ll res = n;
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res += (sg(r) - sg(l - 1)) * x) %= MOD;
        return res * INV2 % MOD;
    }

    int main() {
        pre();
        read(a, b);
        printf("%lld\n", ((sf(b) - sf(a - 1)) % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

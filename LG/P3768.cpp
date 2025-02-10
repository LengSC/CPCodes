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

    constexpr int N = 5e6;

    ll p, n, phi[N + 2], mod, inv6;
    bitset<N + 2> np;
    vi pr;
    unordered_map<ll, ll> mp;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
        return res;
    }

    void pre() {
        phi[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), phi[i] = i - 1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) phi[p] = phi[i] * phi[j] % mod;
                else { phi[p] = phi[i] * j % mod; break; }
            }
        }
        rep(i, 2, N) phi[i] = (phi[i - 1] + phi[i] * i % mod * i) % mod;
    }

    ll s2(ll n) { n %= mod; return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod; }

    ll s3(ll n) { n %= mod; return (n * (n + 1) / 2 % mod) * (n * (n + 1) / 2 % mod) % mod; }

    ll sf(ll n) {
        if (n <= N) return phi[n];
        if (mp[n]) return mp[n];
        ll res = s3(n), l, r, x;
        for (l = 2; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (s2(r) - s2(l - 1)) * sf(x)) %= mod;
        return mp[n] = res;
    }

    ll solve(ll n) {
        ll res = 0, l, r, x;
        for (l = 1; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res += (sf(r) - sf(l - 1)) * s3(x)) %= mod;
        return res;
    }

    int main() {
        read(mod, n);
        pre(); inv6 = fpow(6, mod - 2);
        printf("%lld\n", (solve(n) + mod) % mod);
        return 0;
    }
}

int main() { return SLV::main(); }

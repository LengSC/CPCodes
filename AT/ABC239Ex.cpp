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

    constexpr int MOD = 1e9 + 7;

    unordered_map<ll, ll> f;
    ll n, m, inv;

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll dp(ll x) {
        if (x == 1) return 0;
        if (f[x]) return f[x];
        ll sum = 0, tx = x - 1;
        for (ll l = 2, r, k; l <= n; l = r + 1)
            r = (k = tx / l) ? min(tx / k, n) : n,
            (sum += (r - l + 1) * dp(k + 1)) %= MOD;
        return f[x] = (n + sum) * inv % MOD;
    }

    int main() {
        read(n, m);
        inv = fpow(n - 1);
        printf("%lld\n", dp(m + 1));
        return 0;
    }
}

int main() { return SLV::main(); }

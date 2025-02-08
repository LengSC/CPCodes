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

    constexpr int MOD = 19940417, INV6 = 3323403;

    ll a, b;

    ll f(ll n) {
        ll res = n * n % MOD, l, r, x;
        for (l = 1; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= (l + r) * (r - l + 1) / 2 % MOD * x) %= MOD;
        return res;
    }

    ll s(ll n) {
        return n * (n + 1) % MOD * (2 * n + 1) % MOD * INV6 % MOD;
    }

    ll g(ll n, ll m) {
        if (n > m) swap(n, m);
        ll res = n * n % MOD * m % MOD, l, r, x, y;
        for (l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            (res -= (l + r) * (r - l + 1) / 2 % MOD * (m * x % MOD + n * y % MOD) % MOD) %= MOD,
            (res += (s(r) - s(l - 1)) * x % MOD * y % MOD) %= MOD;
        return res;
    }

    int main() {
        read(a, b);
        printf("%lld\n", (((f(a) * f(b) % MOD - g(a, b)) % MOD) + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

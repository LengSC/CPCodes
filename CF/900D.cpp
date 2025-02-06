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

    ll x, y, n, ans;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll mu(ll x) {
        ll res = 1;
        rep(i, 2, sqrt(x)) {
            if (x % i == 0) {
                x /= i;
                if (x % i == 0) return 0;
                res = -res;
            }
        }
        return (x ^ 1) ? -res : res;
    }

    int main() {
        read(x, y);
        if (y % x) return puts("0"), 0;
        n = y / x;
        rep(d, 1, sqrt(n)) {
            if (n % d) continue;
            (ans += mu(d) * fpow(2, n / d - 1)) %= MOD;
            if (d * d != n) (ans += mu(n / d) * fpow(2, d - 1)) %= MOD;
        }
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

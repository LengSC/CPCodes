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

    constexpr int N = 1e5, MOD = 1e9 + 7;

    ll n, k, a, b, f[N + 2], l, r;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    int main() {
        read(n, k, a, b);
        a = a / k + ((a % k) > 0), b /= k;
        if (a > b) return puts("0"), 0;
        rep(i, 1, b - a) {
            l = a / i + ((a % i) > 0), r = b / i;
            if (l > r) continue;
            f[i] = (fpow(r - l + 1, n) - (r - l + 1)) % MOD;
        }
        per(i, b - a, 1) for (int j = i * 2; j <= b - a; j += i)
            (f[i] -= f[j]) %= MOD;
        printf("%lld\n", (f[1] + (a == 1) + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

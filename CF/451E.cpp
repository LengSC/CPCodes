#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    namespace IO {
        template<typename T>
        void read(T &x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    constexpr int N = 22, MOD = 1e9 + 7;

    ll n, s, f[N], inv[N], ans, sum, sign;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll c(ll a, ll b) {
        ll mul = 1, inv = 1;
        rep(i, 1, b) mul = mul * (a - i + 1) % MOD, inv = inv * i % MOD;
        return mul * fpow(inv, MOD - 2) % MOD;
    }

    ll lucas(ll a, ll b) {
        if (!b) return 1;
        return lucas(a / MOD, b / MOD) * c(a % MOD, b % MOD) % MOD;
    }

    int main() {
        read(n, s);
        rep(i, 1, n) read(f[i]);
        rep(i, 0, (1 << n) - 1) {
            sum = s, sign = 1;
            rep(j, 1, n) if ((i >> (j - 1)) & 1) sum -= f[j] + 1, sign = -sign;
            if (sum >= 0) ans = (ans + lucas(sum + n - 1, n - 1) * sign) % MOD;
        }
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

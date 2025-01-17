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

    constexpr int MOD = 1000000007;

    ll n;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll C(ll n, ll m) {
        ll sum = 1, inv = 1;
        rep(i, 1, m) {
            sum = sum * (n - i + 1) % MOD;
            inv = inv * i % MOD;
        }
        return sum * fpow(inv, MOD - 2) % MOD;
    }

    int main() {
        read(n);
        // ans = 2 * C(2 * n - 1, n) - n
        printf("%lld\n", ((C(2 * n - 1, n) * 2 - n) % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

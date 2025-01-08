#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
    #define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)
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

    constexpr int MOD = 100003;

    ll n, m;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; (a *= a) %= MOD, b >>= 1) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    int main() {
        read(m, n);
        printf("%lld\n", ((fpow(m, n) - m * fpow(m - 1, n - 1)) % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

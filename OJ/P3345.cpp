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

    constexpr int N = 1e6 + 5, MOD = 1e8 + 7;

    ll n, m, lim, f[N], a[N], invm;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }
    
    int main() {
        read(n, m);
        lim = fpow(2, n) - 1;
        a[0] = invm = 1;
        rep(i, 1, m) a[i] = a[i - 1] * (lim - i + 1) % MOD, invm = invm * i % MOD;
        f[0] = 1;
        rep(i, 2, m)
            f[i] = a[i - 1] - f[i - 1] - f[i - 2] * (i - 1) % MOD * (lim - (i - 2)) % MOD;
        printf("%lld\n", (f[m] * fpow(invm, MOD - 2) % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

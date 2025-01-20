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

    constexpr int N = 1e6 + 2, MOD = 1e9 + 7;

    ll t, n, m, fac[N], inv[N], d[N];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    void pre() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % MOD;
        inv[N - 1] = fpow(fac[N - 1], MOD - 2);
        per(i, N - 1, 1) inv[i - 1] = inv[i] * i % MOD;
        d[0] = 1, d[1] = 0;
        rep(i, 2, N - 1) d[i] = (d[i - 1] * i + ((i & 1) ? -1 : 1)) % MOD;
    }

    void solve() {
        read(n, m);
        printf("%lld\n", fac[n] * inv[m] % MOD * inv[n - m] % MOD * d[n - m] % MOD);
    }

    int main() {
        pre();
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

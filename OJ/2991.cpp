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

    constexpr ll N = 2002, MOD = 100003;

    ll a, b, c, d, k, fac[N], inv[N], ans;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll C(ll a, ll b) {
        return b > a ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    int main() {
        read(a, b, c, d, k);
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % MOD;
        inv[N - 1] = fpow(fac[N - 1], MOD - 2);
        per(i, N - 2, 0) inv[i] = inv[i + 1] * (i + 1) % MOD;
        rep(i, 0, k)
            ans = (ans + C(b, i) * C(a, i) % MOD * fac[i] % MOD * C(d, k - i) % MOD * C(a + c - i, k - i) % MOD * fac[k - i] % MOD) % MOD;
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

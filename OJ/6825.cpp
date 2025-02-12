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

    constexpr int N = 1e6 + 5, MOD = 1e9 + 7;

    ll n, k, fac[N], inv[N], ans;

    ll fpow(ll a, ll b, ll p = MOD) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % p) if (b & 1) res = res * a % p;
        return res;
    }

    ll comb(ll n, ll m) {
        return n < m ? 0 : fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    }

    int main() {
        read(n, k);
        fac[0] = 1;
        rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n], MOD - 2);
        per(i, n, 1) inv[i - 1] = inv[i] * i % MOD;
        rep(i, k, n)
            ans = (ans + comb(n - k, i - k) % MOD * (fpow(2, fpow(2, n - i, MOD - 1)) - 1) % MOD * ((i - k) & 1 ? -1 : 1)) % MOD;
        printf("%lld\n", (ans * comb(n, k) % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

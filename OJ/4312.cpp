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

    constexpr int N = 2005, MOD = 1e9 + 9;

    ll n, k, a[N], b[N], fac[N], inv[N], f[N], g[N], ans, cnt[N], last;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll comb(ll a, ll b) {
        return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    int main() {
        read(n, k);
        if ((n + k) & 1) return puts("0"), 0;
        k = (n + k) / 2;
        rep(i, 1, n) read(a[i]); sort(a + 1, a + 1 + n);
        rep(i, 1, n) read(b[i]); sort(b + 1, b + 1 + n);
        rep(i, 1, n) {
            while (last < n && b[last + 1] < a[i]) ++last;
            cnt[i] = last;
        }
        fac[0] = 1;
        rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n], MOD - 2);
        per(i, n, 1) inv[i - 1] = inv[i] * i % MOD;
        f[0] = 1;
        rep(i, 1, n) {
            rep(j, 0, i) g[j] = (f[j] + (cnt[i] - j + 1) * f[j - 1]) % MOD;
            memcpy(f, g, sizeof(f));
        }
	    for (int i = 1; i <= n; ++i) cerr << f[i] << " ";
        rep(i, k, n)
            (ans += ((i - k) & 1 ? -1 : 1) * f[i] * fac[n - i] % MOD * comb(i, k)) %= MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

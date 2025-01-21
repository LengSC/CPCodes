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

    constexpr int N = 6005, MOD = 1e9 + 7;

    ll n, p[N], q[N], fac[N], inv[N], ans, cnt, siz, f[N], g[N];
    bool vis[N];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll comb(ll a, ll b) {
        return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    int main() {
        read(n);
        rep(i, 1, n) read(p[i]);
        rep(i, 1, n) read(q[p[i]]);

        fac[0] = 1;
        rep(i, 1, n * 2) fac[i] = fac[i - 1] * i % MOD;
        inv[n * 2] = fpow(fac[n * 2], MOD - 2);
        per(i, n * 2, 1) inv[i - 1] = inv[i] * i % MOD;

        f[0] = 1;
        rep(i, 1, n) if (!vis[i]) {
            for (int j = i; !vis[j]; j = q[j]) ++siz, vis[j] = true;
            if (siz == 1) per(j, cnt + 1, 1) f[j] = (f[j] + f[j - 1]) % MOD;
            else {
                memset(g, 0, sizeof(g));
                per(j, cnt, 0) per(k, siz, 0)
                    g[j + k] = (g[j + k] + f[j] * (comb(2 * siz - k, k) + comb(2 * siz - k - 1, k - 1))) % MOD;
                memcpy(f, g, sizeof(g));
            }
            cnt += siz;
            siz = 0;
        }
        
        per(i, n, 0) ans = (ans + (i & 1 ? -1 : 1) * f[i] * fac[n - i]) % MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

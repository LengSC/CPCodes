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

    constexpr int N = 2005, MOD = 1e9 + 7;

    ll n, a, fac[N], inv[N], ans, fixxed, avlb;
    bool free[N], vis[N];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll comb(ll a, ll b) {
        return (a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD);
    }

    /**
     * free[i]: 下标 i 可用
     * vis[i]:  数字 i 已用
     * fixxed:  已用数字数量
     * avlb:    可能不合法的数量
     * 
     * Ans = \sum \limits_{i = 0}^{avlb}{(-1)^{i} \cdot \binom{avlb}{i} \cdot (n - fixxed - i)!}
     */

    int main() {
        read(n);
        fac[0] = 1;
        rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n], MOD - 2);
        per(i, n, 1) inv[i - 1] = inv[i] * i % MOD;
        rep(i, 1, n) {
            read(a);
            if (a == i) return puts("0"), 0;
            if (a == -1) free[i] = true;
            else vis[a] = true, ++fixxed;
        }
        rep(i, 1, n) if (!vis[i] && free[i]) ++avlb;
        rep(i, 0, avlb)
            ans = (ans + comb(avlb, i) * fac[n - fixxed - i] % MOD * (i & 1 ? -1 : 1)) % MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

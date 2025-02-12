#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    using vi = vector<int>;
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

    constexpr int N = 20, MOD = 998244353;

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll n, q, x, tu, tv, k[N], b[N], f[1 << N], lim;
    vi g[N];
    bool vis[N];
    /* k[], b[]: https://www.luogu.com.cn/article/hbo189ev */

    void dfs(ll u, ll fa) {
        if (vis[u]) return k[u] = b[u] = 0, void();
        ll deg = 0, sumk = 0, sumb = 0;
        for (const auto &v: g[u]) {
            ++deg;
            if (v == fa) continue;
            dfs(v, u);
            (sumk += k[v]) %= MOD;
            (sumb += b[v]) %= MOD;
        }
        k[u] = fpow(((deg - sumk) % MOD + MOD) % MOD);
        b[u] = (deg + sumb) * fpow(((deg - sumk) % MOD + MOD) % MOD);
    }

    int main() {
        read(n, q, x); lim = 1 << n;
        dep(i, 1, n) read(tu, tv), g[tu].eb(tv), g[tv].eb(tu);
        dep(i, 1, lim) {
            rep(j, 1, n) vis[j] = (i >> (j - 1)) & 1;
            dfs(x, 0);
            f[i] = b[x];
        }
        dep(i, 1, lim) if (!(__builtin_popcount(i) & 1)) f[i] = -f[i];
        dep(i, 0, n) dep(j, 1, lim)
            if (j & (1 << i)) (f[j] += f[j ^ (1 << i)]) %= MOD;
        rep(i, 1, q) {
            read(x);
            ll s = 0, t;
            rep(i, 1, x) read(t), s |= 1 << (t - 1);
            printf("%lld\n", (f[s] + MOD) % MOD);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

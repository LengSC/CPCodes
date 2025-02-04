#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
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

    ll n, a, g[N], ans = 1, mx;
    bool vis[N];

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    int main() {
        read(n);
        rep(i, 1, n) read(a), mx = max(mx, a), vis[a] = true;
        g[1] = 1;
        rep(i, 2, mx) g[i] = (g[i - 1] + g[i - 2]) % MOD;
        rep(i, 1, mx) {
            for (int j = 2 * i, inv = fpow(g[i]); j <= mx; j += i)
                g[j] = g[j] * inv % MOD;
            for (int j = i; j <= mx; j += i)
                if (vis[j]) {
                    (ans *= g[i]) %= MOD;
                    break;
                }
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

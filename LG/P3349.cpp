#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
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

    constexpr int N = 20;

    int n, m, tu, tv, lim, vis[N], mp[N][N];
    vector<int> g[N];
    ll f[N][N], ans;

    void dp(int u, int fa, int s) {
        rep(i, 1, vis[0]) f[u][i] = 1;
        for (const auto &v: g[u]) {
            if (v == fa) continue;
            dp(v, u, s);
            rep(i, 1, vis[0]) {
                ll tmp = 0;
                rep(j, 1, vis[0])
                    if (mp[vis[i]][vis[j]]) tmp += f[v][j];
                f[u][i] *= tmp;
            }
        }
    }

    int main() {
        read(n, m); lim = (1 << n) - 1;
        rep(i, 1, m)
            read(tu, tv), mp[tu][tv] = mp[tv][tu] = 1;
        rep(i, 1, n - 1)
            read(tu, tv), g[tu].eb(tv), g[tv].eb(tu);
        rep(s, 0, lim) {
            vis[0] = 0;
            rep(i, 1, n) if (s & (1 << (i - 1))) vis[++vis[0]] = i;
            dp(1, 0, s);
            ll tmp = 0;
            rep(i, 1, vis[0]) tmp += f[1][i];
            ans += (n - __builtin_popcount(s)) & 1 ? -tmp : tmp;
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 1e5 + 5, LOGN = 17, M = 305, MOD = 1e9 + 7;

    int n, q, tu, tv, k, m, r, f[2][M], kp[N], ord[N], ans, now;
    vi g[N];

    namespace BIT {
        int c[N];

        void add(int x, int val) { for (; x <= n; x += x & -x) c[x] += val; }

        int qry(int x) {
            int res = 0;
            for (; x; x ^= x & -x) res += c[x];
            return res;
        }
    }

    namespace HLD {
        int dfn[N], sz[N], dep[N], fa[N][LOGN], idx;

        void dfs(int u, int tfa) {
            fa[u][0] = tfa;
            dep(i, 1, LOGN) fa[u][i] = fa[fa[u][i - 1]][i - 1];
            dep[u] = dep[tfa] + 1, dfn[u] = ++idx, sz[u] = 1;
            for (const auto v: g[u])
                if (v != tfa) dfs(v, u), sz[u] += sz[v];
        }

        int lca(int u, int v) {
            if (dep[u] < dep[v]) swap(u, v);
            per(i, LOGN - 1, 0) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
            if (u == v) return u;
            per(i, LOGN - 1, 0) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
            return fa[u][0];
        }

        void addu(int u, int val) { BIT::add(dfn[u], val), BIT::add(dfn[u] + sz[u], -val); }

        int qry(int u, int v) {
            int l = lca(u, v);
            return BIT::qry(dfn[u]) + BIT::qry(dfn[v]) - BIT::qry(dfn[l]) - BIT::qry(dfn[fa[l][0]]);
        }
    }

    void solve() {
        read(k, m, r);
        rep(i, 1, k) read(kp[i]), HLD::addu(kp[i], 1);
        rep(i, 1, k) ord[kp[i]] = HLD::qry(kp[i], r) - 1;
        sort(kp + 1, kp + 1 + k, [](const int &lhs, const int &rhs) { return ord[lhs] < ord[rhs]; });
        now = 0; memset(f[now], 0, sizeof(f[0])); f[now][0] = 1;
        rep(i, 1, k) {
            now ^= 1;
            memset(f[now], 0, sizeof(f[now]));
            rep(j, ord[kp[i]], m)
                f[now][j] = ((ll)(j - ord[kp[i]]) * f[!now][j] + f[!now][j - 1]) % MOD;
        }
        ans = 0; rep(i, 1, m) (ans += f[now][i]) %= MOD;
        printf("%d\n", ans);
        rep(i, 1, k) HLD::addu(kp[i], -1);
    }

    int main() {
        read(n, q);
        dep(i, 1, n) read(tu, tv), g[tu].eb(tv), g[tv].eb(tu);
        HLD::dfs(1, 0);
        rep(i, 1, q) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

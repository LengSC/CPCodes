#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    using uint = unsigned int;
    using ll = long long;
    using ull = unsigned long long;
    using vi = vector<int>;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 1e6 + 5;

    int n, deg[N], f[N], son[N], fat[N];
    vi g[N];

    void dfs(int u, int fa) {
        for (const auto &v: g[u]) {
            if (v == fa) continue;
            son[u] ? fat[u] = v : son[u] = v;
            dfs(v, u);
        }
        if (!son[u]) f[u] = u;
        else if (!fat[u]) {
            f[u] = min(f[son[u]], u);
            if (f[son[u]] > u) swap(son[u], fat[u]);
        } else {
            f[u] = min(f[son[u]], f[fat[u]]);
            if (f[son[u]] > f[fat[u]]) swap(son[u], fat[u]);
        }
    }

    void print(int u) {
        if (!u) return;
        if (son[u]) print(son[u]);
        printf("%d ", u);
        if (fat[u]) print(fat[u]);
    }

    void solve(int u) {
        printf("%d ", u);
        if (!son[u]) swap(son[u], fat[u]);
        if (!son[u]) return;
        if (fat[u]) print(son[u]), solve(fat[u]);
        else if (son[u] <= f[son[u]]) solve(son[u]);
        else print(son[u]);
    }

    int main() {
        read(n);
        rep(u, 1, n) {
            read(deg[u]); int v;
            rep(j, 1, deg[u]) read(v), g[u].eb(v);
        }
        rep(u, 1, n) if (deg[u] <= 2) return dfs(u, 0), solve(u), 0;
        return 0;
    }
}

int main() { return SLV::main(); }

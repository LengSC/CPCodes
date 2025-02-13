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

    constexpr int N = 1e6 + 2;

    int n, m, pi[N], j, fa[N][21], dep[N], x, y;
    char s[N];

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[u] - dep[v];
        per(i, 20, 0)
            if (d & (1 << i)) u = fa[u][i];
        if (u == v) return u;
        per(i, 20, 0)
            if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
        return fa[u][0];
    }

    int main() {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        read(m);
        rep(i, 2, n) {
            while (j && s[i] != s[j + 1]) j = pi[j];
            if (s[i] == s[j + 1]) ++j;
            pi[i] = j;
        }
        rep(u, 1, n) {
            fa[u][0] = pi[u];
            dep[u] = dep[pi[u]] + 1;
            for (int i = 1; i <= 20; ++i)
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        rep(i, 1, m) {
            read(x, y);
            int l = lca(x, y);
            if (l == x || l == y) printf("%d\n", fa[l][0]);
            else printf("%d\n", l);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

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

constexpr int N = 3e5 + 2, LOGN = 20;

int n, fa[N][LOGN], dep[N], x, y, ver[N];
char op;

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    per(i, LOGN - 1, 0) if (d & (1 << i)) u = fa[u][i];
    if (u == v) return u;
    per(i, LOGN - 1, 0) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int main() {
    read(n);
    rep(i, 1, n) {
        scanf("%c", &op); read(x);
        switch (op) {
        case 'a':
            ver[i] = i;
            dep[i] = dep[ver[x]] + 1, fa[i][0] = ver[x];
            dep(j, 1, LOGN) fa[i][j] = fa[fa[i][j - 1]][j - 1];
            break;
        case 'b':
            ver[i] = fa[ver[x]][0];
            printf("%d\n", ver[x]);
            break;
        case 'c':
            read(y);
            printf("%d\n", dep[lca(ver[i] = ver[x], ver[y])]);
            break;
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

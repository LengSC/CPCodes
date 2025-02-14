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

constexpr int N = 2e5 + 2;

int n, u, v, a[N], f[N], ans[N], cnt;
vi g[N];

void dfs(int u, int fa) {
    bool flg = false;
    int *tp, lst;
    if (f[cnt] < a[u]) f[++cnt] = a[u], flg = true;
    else
        tp = lower_bound(f + 1, f + 1 + cnt, a[u]),
        lst = *tp, *tp = a[u];
    ans[u] = cnt;
    for (const auto &v: g[u]) if (v != fa) dfs(v, u);
    if (flg) --cnt;
    else *tp = lst;
}

int main() {
    read(n);
    rep(i, 1, n) read(a[i]);
    dep(i, 1, n) read(u, v), g[u].eb(v), g[v].eb(u);
    dfs(1, 0);
    rep(i, 1, n) printf("%d\n", ans[i]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

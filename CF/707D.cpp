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

constexpr int N = 1002, Q = 1e5 + 2;

int n, m, t, ans[Q];
bitset<N> mat[N], txor;
vi g[Q];
struct Query { int op, x, y, id; } q[Q];

void dfs(int u, int popcnt) {
    int tmp = 0;
    switch (q[u].op) {
    case 1:
        tmp = mat[q[u].x][q[u].y];
        popcnt += !tmp;
        mat[q[u].x][q[u].y] = true;
        break;
    case 2:
        tmp = mat[q[u].x][q[u].y];
        popcnt -= tmp;
        mat[q[u].x][q[u].y] = false;
        break;
    case 3:
        tmp = mat[q[u].x].count();
        mat[q[u].x] ^= txor;
        popcnt += mat[q[u].x].count() - tmp;
        break;
    }
    ans[q[u].id] = popcnt;
    for (const auto &v: g[u]) dfs(v, popcnt);
    switch(q[u].op) {
    case 1:
    case 2: mat[q[u].x][q[u].y] = tmp; break;
    case 3: mat[q[u].x] ^= txor; break;
    }
}

int main() {
    read(n, m, t);
    rep(i, 1, m) txor.set(i);
    rep(i, 1, t) {
        read(q[i].op, q[i].x); q[i].id = i;
        if (q[i].op == 4) g[q[i].x].eb(i);
        else {
            if (q[i].op != 3) read(q[i].y);
            g[i - 1].eb(i);
        }
    }
    dfs(0, 0);
    rep(i, 1, t) printf("%d\n", ans[i]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

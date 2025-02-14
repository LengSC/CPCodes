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

constexpr int N = 52;

int n, m, a[N][N], f[N][N][N][N];

int main() {
    read(n, m);
    rep(i, 1, n) rep(j, 1, m) read(a[i][j]);
    rep(i, 1, n) rep(j, 1, m) rep(p, i + 1, n) rep(q, 1, j - 1)
        f[i][j][p][q] = max({f[i - 1][j][p - 1][q], f[i - 1][j][p][q - 1], f[i][j - 1][p - 1][q], f[i][j - 1][p][q - 1]}) + a[i][j] + a[p][q];
    printf("%d\n", f[n - 1][m][n][m - 1]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

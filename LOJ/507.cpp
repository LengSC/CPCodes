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

int n, k, c[N];
ll v[N], f[N], mx[N];

int main() {
    read(n, k);
    rep(i, 1, n) read(c[i]);
    rep(i, 1, n) read(v[i]), v[i] += v[i - 1];
    memset(mx, -63, sizeof(mx));
    rep(i, 1, n) {
        f[i] = max(f[i - 1], mx[c[i]] + v[i]);
        mx[c[i]] = max(mx[c[i]], f[i - 1] - v[i - 1]);
    }
    printf("%lld\n", f[n]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

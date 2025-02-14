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

constexpr int N = 1e6 + 2, INF = 0x3f3f3f3f;
constexpr ull BASE = 998244353;

int la[N], ra[N], lb[N], rb[N], a[N], b[N], n, m;
map<string, int> lst;
string t;
ull pw[N], ha, hb;

int main() {
    while (cin >> t, t != "$") ra[lst[t]] = ++n, la[n] = lst[t], lst[t] = n;
    lst.clear();
    while (cin >> t, t != "$") rb[lst[t]] = ++m, lb[m] = lst[t], lst[t] = m;
    rep(i, 1, n) if (!ra[i]) ra[i] = INF;
    rep(i, 1, m) if (!rb[i]) rb[i] = INF;
    rep(i, 1, n) a[i] = la[i] ? i - la[i] : -1;
    rep(i, 1, m) b[i] = lb[i] ? i - lb[i] : -1;
    pw[0] = 1;
    rep(i, 1, m)
        pw[i] = pw[i - 1] * BASE,
        ha = ha * BASE + a[i],
        hb = hb * BASE + b[i];
    if (ha == hb) return puts("1"), 0;
    rep(i, m + 1, n) {
        ha = ha * BASE + a[i] - a[i - m] * pw[m];
        if (ra[i - m] <= i) {
            ha -= a[ra[i - m]] * pw[i - ra[i - m]];
            a[ra[i - m]] = -1;
            ha += a[ra[i - m]] * pw[i - ra[i - m]];
        } else if (ra[i - m] <= n) a[ra[i - m]] = -1;
        if (ha == hb) return printf("%d\n", i - m + 1), 0;
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

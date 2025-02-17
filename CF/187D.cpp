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

constexpr int N = 1e5 + 5;

int n, q, g, per, x;
map<int, int> odt;
ll a[N], d[N];

void assign(int l, int r, int v) {
    auto itl = odt.lower_bound(l), itr = odt.upper_bound(r);
    int tmp = prev(itr)->second;
    odt.erase(itl, itr);
    odt[l] = v, odt[r] = tmp;
}

int main() {
    read(n, g, per); per += g; odt[0] = -1;
    rep(i, 1, n + 1) read(a[i]), a[i] += a[i - 1];
    per(i, n, 1) {
        int l = (g - a[i] % per + per) % per, r = (per - a[i] % per) % per, j = prev(odt.upper_bound(r))->second;
        d[i] = j == -1 ? a[n + 1] - a[i] : (a[j] - a[i] + per - 1) / per * per + d[j];
        if (l < r) assign(l, r, i);
        else assign(0, r, i), assign(l, per, i);
    }
    for (read(q); q; --q) {
        read(x);
        int j = prev(odt.upper_bound(x % per))->second;
        printf("%lld\n", j == -1 ? x + a[n + 1] : (x + a[j] + per - 1) / per * per + d[j]);
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

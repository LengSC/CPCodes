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

int n, m, a[N], ql, qr, pre[N], ans[N];
vector<pii> q[N];

namespace BIT {
    int c[N];

    void add(int x, int val) { for (; x <= n; x += x & -x) c[x] += val; }

    int qry(int x) {
        int res = 0;
        for (; x; x ^= x & -x) res += c[x];
        return res;
    }
}

int main() {
    read(n);
    rep(i, 1, n) read(a[i]);
    read(m);
    rep(i, 1, m) read(ql, qr), q[qr].eb(ql, i);
    rep(r, 1, n) {
        BIT::add(pre[a[r]] + 1, 1);
        BIT::add(r + 1, -1);
        for (auto qry: q[r]) ans[qry.se] = BIT::qry(qry.fi);
        pre[a[r]] = r;
    }
    rep(i, 1, m) printf("%d\n", ans[i]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

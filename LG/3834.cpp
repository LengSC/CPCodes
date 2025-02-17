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

constexpr int N = 2e5 + 2, M = 1e7 + 2;

int n, m, p, len, a[N], b[N], l, r, k;

namespace PERSEG {
    #define ls(t) (tr[t].lson)
    #define rs(t) (tr[t].rson)
    #define mid ((l + r) / 2)
    struct Node {
        int lson, rson, sum;
    } tr[M];

    int cnt, root[N];

    void modify(int &cur, int l, int r) {
        tr[++cnt] = tr[cur], cur = cnt, ++tr[cur].sum;
        if (l == r) return;
        if (p <= mid) modify(ls(cur), l, mid);
        else modify(rs(cur), mid + 1, r);
    }

    int kthmax(int u, int v, int l, int r, int k) {
        if (l == r) return l;
        int d = tr[ls(v)].sum - tr[ls(u)].sum;
        if (k <= d) return kthmax(ls(u), ls(v), l, mid, k);
        else return kthmax(rs(u), rs(v), mid + 1, r, k - d);
    }
    #undef ls
    #undef rs
    #undef mid
} using namespace PERSEG;

int main() {
    read(n, m);
    rep(i, 1, n) read(a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    len = unique(b + 1, b + 1 + n) - b - 1;
    rep(i, 1, n) {
        p = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        root[i] = root[i - 1];
        modify(root[i], 1, len);
    }
    rep(i, 1, m) {
        read(l, r, k);
        printf("%d\n", b[kthmax(root[l - 1], root[r], 1, len, k)]);
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

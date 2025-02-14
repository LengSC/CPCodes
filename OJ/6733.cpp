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

constexpr int N = 1e6 + 2, M = 2.5e7 + 2;

int n, m, a[N], op, x, y, z;

namespace PERSEG {
    #define ls (tr[cur].lson)
    #define rs (tr[cur].rson)
    #define mid ((l + r) / 2)
    struct Node {
        int lson, rson, val;
    } tr[M];

    int cnt, root[N];

    void newNode(int &cur, int src) { tr[cur = ++cnt] = tr[src]; }

    void build(int &cur, int l, int r) {
        cur = ++cnt;
        if (l == r) return tr[cur].val = a[l], void();
        build(ls, l, mid), build(rs, mid + 1, r);
    }

    void modify(int &cur, int l, int r, int x, int val) {
        newNode(cur, cur);
        if (l == r) return tr[cur].val = val, void();
        if (x <= mid) modify(ls, l, mid, x, val);
        else modify(rs, mid + 1, r, x, val);
    }

    int qry(int cur, int l, int r, int x) {
        if (l == r) return tr[cur].val;
        if (x <= mid) return qry(ls, l, mid, x);
        else return qry(rs, mid + 1, r, x);
    }
    #undef ls
    #undef rs
    #undef mid
} using namespace PERSEG;

int main() {
    read(n, m);
    rep(i, 1, n) read(a[i]);
    build(root[0], 1, n);
    rep(i, 1, m) {
        read(op, x, y);
        if (op == 1) {
            read(z);
            root[i] = root[x];
            modify(root[i], 1, n, y, z);
        } else {
            root[i] = root[x];
            printf("%d\n", qry(root[i], 1, n, y));
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

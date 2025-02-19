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

constexpr int N = 1e5 + 2, INF = 1e9;

int n, m, a[N], x, y, z;
char op;

namespace SEG {
    #define ls (cur << 1)
    #define rs (cur << 1 | 1)
    #define mid ((l + r) >> 1)
    void chkmax(int &a, int b) { a = max(a, b); }

    struct Node {
        int mx, hmx, add, hma, cvr, hmc;
        bool cvred;
    } tr[N << 2];

    void mAdd(int cur, int tag, int hmt) {
        if (tr[cur].cvred) {
            chkmax(tr[cur].hmx, tr[cur].mx + hmt);
            chkmax(tr[cur].hmc, tr[cur].cvr + hmt);
            tr[cur].mx += tag;
            tr[cur].cvr += tag;
        } else {
            chkmax(tr[cur].hmx, tr[cur].mx + hmt);
            chkmax(tr[cur].hma, tr[cur].add + hmt);
            tr[cur].mx += tag;
            tr[cur].add += tag;
        }
    }

    void mCvr(int cur, int tag, int hmt) {
        if (tr[cur].cvred) {
            chkmax(tr[cur].hmx, hmt);
            chkmax(tr[cur].hmc, hmt);
            tr[cur].mx = tr[cur].cvr = tag;
        } else {
            tr[cur].cvred = true;
            chkmax(tr[cur].hmx, hmt);
            tr[cur].hmc = hmt;
            tr[cur].mx = tr[cur].cvr = tag;
        }
    }

    void down(int cur) {
        mAdd(ls, tr[cur].add, tr[cur].hma);
        mAdd(rs, tr[cur].add, tr[cur].hma);
        tr[cur].add = tr[cur].hma = 0;
        if (tr[cur].cvred) {
            mCvr(ls, tr[cur].cvr, tr[cur].hmc);
            mCvr(rs, tr[cur].cvr, tr[cur].hmc);
            tr[cur].cvred = false;
            tr[cur].cvr = tr[cur].hmc = 0;
        }
    }

    void up(int cur) {
        tr[cur].mx = max(tr[ls].mx, tr[rs].mx);
        tr[cur].hmx = max(tr[ls].hmx, tr[rs].hmx);
    }

    void build(int cur, int l, int r) {
        if (l == r) return tr[cur].mx = tr[cur].hmx = a[l], void();
        build(ls, l, mid), build(rs, mid + 1, r);
        up(cur);
    }

    void uAdd(int cur, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) return mAdd(cur, val, val);
        down(cur);
        uAdd(ls, l, mid, ql, qr, val), uAdd(rs, mid + 1, r, ql, qr, val);
        up(cur);
    }

    void uCvr(int cur, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) return mCvr(cur, val, val);
        down(cur);
        uCvr(ls, l, mid, ql, qr, val), uCvr(rs, mid + 1, r, ql, qr, val);
        up(cur);
    }

    int qMs(int cur, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return -INF;
        if (ql <= l && r <= qr) return tr[cur].mx;
        down(cur);
        return max(qMs(ls, l, mid, ql, qr), qMs(rs, mid + 1, r, ql, qr));
    }

    int qHms(int cur, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return -INF;
        if (ql <= l && r <= qr) return tr[cur].hmx;
        down(cur);
        return max(qHms(ls, l, mid, ql, qr), qHms(rs, mid + 1, r, ql, qr));
    }
    #undef ls
    #undef rs
    #undef mid
}

int main() {
    read(n);
    rep(i, 1, n) read(a[i]);
    SEG::build(1, 1, n);
    read(m);
    rep(i, 1, m) {
        scanf(" %c", &op), read(x, y);
        switch (op) {
        case 'Q': printf("%d\n", SEG::qMs(1, 1, n, x, y)); break;
        case 'A': printf("%d\n", SEG::qHms(1, 1, n, x, y)); break;
        case 'P': read(z); SEG::uAdd(1, 1, n, x, y, z); break;
        case 'C': read(z); SEG::uCvr(1, 1, n, x, y, z); break;
        default: assert(false);
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

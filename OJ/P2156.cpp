#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    namespace IO {
        template<typename T>
        void read(T &x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    constexpr int N = 20005;

    struct Rect {
        int xa, ya, xb, yb;
    } ra[N], rb[N];

    struct Line {
        int x, l, r, v;
    } q[N << 1];

    int n, mp[N << 1], xa, ya, xb, yb;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int sum, num;
        } tr[N << 2];

        void up(int cur, int l, int r) {
            if (tr[cur].num) tr[cur].sum = mp[r + 1] - mp[l];
            else if (l == r) tr[cur].sum = 0;
            else tr[cur].sum = tr[ls].sum + tr[rs].sum;
        }

        void build(int cur, int l, int r) {
            tr[cur] = {0, 0};
            if (l == r) return;
            build(ls, l, mid), build(rs, mid + 1, r);
        }

        void modify(int cur, int l, int r, int ql, int qr, int v) {
            if (ql <= l && r <= qr) return tr[cur].num += v, up(cur, l, r);
            if (qr < l || ql > r) return;
            if (ql <= mid) modify(ls, l, mid, ql, qr, v);
            if (qr > mid) modify(rs, mid + 1, r, ql, qr, v);
            up(cur, l, r);
        }
        #undef ls
        #undef rs
        #undef mid
    } using namespace SGT;

    int scanline(Rect r[]) {
        int res = 0, last = 0, cnt = 0, qcnt = 0;
        rep(i, 1, n)
            q[++qcnt] = {r[i].xa, r[i].ya, r[i].yb, 1},
            q[++qcnt] = {r[i].xb, r[i].ya, r[i].yb, -1},
            mp[++cnt] = r[i].ya, mp[++cnt] = r[i].yb;
        sort(mp + 1, mp + 1 + cnt);
        cnt = unique(mp + 1, mp + 1 + cnt) - mp - 1;
        sort(q + 1, q + 1 + qcnt, [](const Line &a, const Line &b) {
            return a.x == b.x ? a.v > b.v : a.x < b.x;
        });
        build(1, 1, cnt);
        rep(i, 1, qcnt) {
            int l = lower_bound(mp + 1, mp + 1 + cnt, q[i].l) - mp,
                r = lower_bound(mp + 1, mp + 1 + cnt, q[i].r) - mp - 1;
            modify(1, 1, cnt, l, r, q[i].v);
            res += abs(tr[1].sum - last);
            last = tr[1].sum;
        }
        return res;
    }

    int main() {
        read(n);
        rep(i, 1, n)
            read(xa, ya, xb, yb),
            ra[i] = {xa, ya, xb, yb},
            rb[i] = {ya, xa, yb, xb};
        printf("%d\n", scanline(ra) + scanline(rb));
        return 0;
    }
}

int main() { return SLV::main(); }

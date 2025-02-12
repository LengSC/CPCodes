#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (int i = st, e##i = ed; i >= e##i; --i)

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
}
using namespace IO;

namespace SGT {
    #define lc (cur << 1)
    #define rc (cur << 1 | 1)
    #define mid ((l + r) >> 1)
    struct {
        struct {
            int l, r, clr, cvr;
        } tr[800005];

        void down(int cur) {
            if (!~tr[cur].cvr) return;
            tr[lc].clr = tr[rc].clr = tr[cur].cvr;
            tr[lc].cvr = tr[rc].cvr = tr[cur].cvr;
            tr[cur].cvr = -1;
        }

        void build(int cur, int l, int r) {
            tr[cur].l = l, tr[cur].r = r, tr[cur].cvr = -1;
            if (l == r) return;
            build(lc, l, mid), build(rc, mid + 1, r);
        }

        void uCvr(int cur, int l, int r, int v) {
            if (tr[cur].r < l || tr[cur].l > r) return;
            if (l <= tr[cur].l && tr[cur].r <= r)
                return tr[cur].clr = tr[cur].cvr = v, void();
            down(cur);
            uCvr(lc, l, r, v);
            uCvr(rc, l, r, v);
        }

        int qClr(int cur, int x) {
            if (tr[cur].l == tr[cur].r) return tr[cur].clr;
            down(cur);
            if (x <= ((tr[cur].l + tr[cur].r) >> 1)) return qClr(lc, x);
            return qClr(rc, x);
        }
    } st;
    #undef lc
    #undef rc
    #undef mid
}
using namespace SGT;

namespace SLV {
    int xc, n, l, r, c, ans, las, now;
    int main() {
        read(xc, n);
        st.build(1, 1, 200000);
        st.uCvr(1, 1, 200000, xc);
        rep(i, 1, n) {
            read(l, r, c);
            st.uCvr(1, l + 100001, r + 100000, c);
        }
        rep(i, 1, 200000) {
            if ((now = st.qClr(1, i)) == las) continue;
            ++ans, las = now;
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }
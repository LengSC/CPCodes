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

constexpr int N = 1e6 + 5;

namespace SGT {
    #define lc (cur << 1)
    #define rc (cur << 1 | 1)
    #define mid ((l + r) >> 1)
    struct {
        struct {
            int l, r, sum, cvr;
        } tr[N << 2];

        void down(int cur) {
            if (!~tr[cur].cvr) return;
            tr[lc].sum = tr[cur].cvr * (tr[lc].r - tr[lc].l + 1);
            tr[lc].cvr = tr[cur].cvr;
            tr[rc].sum = tr[cur].cvr * (tr[rc].r - tr[rc].l + 1);
            tr[rc].cvr = tr[cur].cvr;
            tr[cur].cvr = -1;
        }

        void up(int cur) {
            tr[cur].sum = tr[lc].sum + tr[rc].sum;
        }

        void build(int cur, int l, int r) {
            tr[cur].l = l, tr[cur].r = r;
            if (l == r) return;
            build(lc, l, mid), build(rc, mid + 1, r);
        }

        void uCvr(int cur, int l, int r, int v) {
            if (tr[cur].r < l || tr[cur].l > r) return;
            if (l <= tr[cur].l && tr[cur].r <= r)
                return tr[cur].sum = v * (tr[cur].r - tr[cur].l + 1),
                tr[cur].cvr = v,
                void();
            down(cur);
            uCvr(lc, l, r, v), uCvr(rc, l, r, v);
            up(cur);
        }

        int qSum(int cur, int l, int r) {
            if (tr[cur].r < l || tr[cur].l > r) return 0;
            if (l <= tr[cur].l && tr[cur].r <= r) return tr[cur].sum;
            down(cur);
            return qSum(lc, l, r) + qSum(rc, l, r);
        }
    } st;
    #undef lc
    #undef rc
    #undef mid
}
using namespace SGT;

namespace SLV {
    int n, m, op, l, r;

    int main() {
        read(n, m);
        st.build(1, 1, n - 1);
        rep(i, 1, m) {
            read(op, l, r);
            if (op == 1) st.uCvr(1, l, r - 1, 1);
            else st.uCvr(1, l, r - 1, 0);
        }
        printf("%d\n", st.qSum(1, 1, n - 1));
        return 0;
    }
}

int main() { return SLV::main(); }
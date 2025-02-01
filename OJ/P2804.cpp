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

    constexpr int N = 1005;

    int d, s, n, td, ts, tw, tx, ty;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)

        struct SgtY {
            int tag[N << 2], val[N << 2];

            void modify(int cur, int l, int r, int ql, int qr, int v) {
                val[cur] = max(val[cur], v);
                if (ql == l && qr == r) return tag[cur] = max(tag[cur], v), void();
                if (qr <= mid) modify(ls, l, mid, ql, qr, v);
                else if (ql > mid) modify(rs, mid + 1, r, ql, qr, v);
                else modify(ls, l, mid, ql, mid, v), modify(rs, mid + 1, r, mid + 1, qr, v);
            }

            int qry(int cur, int l, int r, int ql, int qr) {
                if (ql == l && qr == r) return val[cur];
                if (qr <= mid) return max(tag[cur], qry(ls, l, mid, ql, qr));
                else if (ql > mid) return max(tag[cur], qry(rs, mid + 1, r, ql, qr));
                else return max({tag[cur], qry(ls, l, mid, ql, mid), qry(rs, mid + 1, r, mid + 1, qr)});
            }
        };

        struct SgtX {
            SgtY tag[N << 2], val[N << 2];

            void modify(int cur, int l, int r, int ql, int qr, int yl, int yr, int v) {
                val[cur].modify(1, 1, s, yl, yr, v);
                if (ql == l && qr == r) return tag[cur].modify(1, 1, s, yl, yr, v), void();
                if (qr <= mid) modify(ls, l, mid, ql, qr, yl, yr, v);
                else if (ql > mid) modify(rs, mid + 1, r, ql, qr, yl, yr, v);
                else modify(ls, l, mid, ql, mid, yl, yr, v), modify(rs, mid + 1, r, mid + 1, qr, yl, yr, v);
            }

            int qry(int cur, int l, int r, int ql, int qr, int yl, int yr) {
                if (ql == l && qr == r) return val[cur].qry(1, 1, s, yl, yr);
                int tmp = tag[cur].qry(1, 1, s, yl, yr);
                if (qr <= mid) return max(tmp, qry(ls, l, mid, ql, qr, yl, yr));
                else if (ql > mid) return max(tmp, qry(rs, mid + 1, r, ql, qr, yl, yr));
                else return max({tmp, qry(ls, l, mid, ql, mid, yl, yr), qry(rs, mid + 1, r, mid + 1, qr, yl, yr)});
            }
        } sgt;
        #undef ls
        #undef rs
        #undef mid
    } using SGT::sgt;

    int main() {
        read(d, s, n);
        rep(i, 1, n) {
            read(td, ts, tw, tx, ty);
            sgt.modify(1, 1, d, tx + 1, tx + td, ty + 1, ty + ts, sgt.qry(1, 1, d, tx + 1, tx + td, ty + 1, ty + ts) + tw);
        }
        printf("%d\n", sgt.qry(1, 1, d, 1, d, 1, s));
        return 0;
    }
}

int main() { return SLV::main(); }

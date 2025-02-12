#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
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

    constexpr int N = 5e5 + 2;

    int n, m;
    int op, x, d, ans;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct {
            int sum, len, prex, sufx, cvr;
        } tr[N << 2];

        void build(int cur, int l, int r) {
            tr[cur].sum = tr[cur].len = tr[cur].prex = tr[cur].sufx = r - l + 1;
            if (l == r) return;
            build(ls, l, mid);
            build(rs, mid + 1, r);
        }

        void up(int cur) {
            tr[cur].prex = (tr[ls].prex == tr[ls].len) ? tr[ls].len + tr[rs].prex : tr[ls].prex;
            tr[cur].sufx = (tr[rs].sufx == tr[rs].len) ? tr[ls].sufx + tr[rs].len : tr[rs].sufx;
            tr[cur].sum = max({tr[ls].sufx + tr[rs].prex, tr[ls].sum, tr[rs].sum});
        }

        void down(int cur) {
            // cvr: 1: Free rooms; -1: Book rooms
            if (!tr[cur].cvr) return;
            tr[ls].cvr = tr[rs].cvr = tr[cur].cvr;
            tr[ls].sum = tr[ls].prex = tr[ls].sufx = (tr[cur].cvr == 1) ? tr[ls].len : 0;
            tr[rs].sum = tr[rs].prex = tr[rs].sufx = (tr[cur].cvr == 1) ? tr[rs].len : 0;
            tr[cur].cvr = 0;
        }

        void uCvr(int cur, int l, int r, int ql, int qr, int v) {
            if (ql <= l && r <= qr) {
                tr[cur].sum = tr[cur].prex = tr[cur].sufx = (v == 1) ? tr[cur].len : 0;
                tr[cur].cvr = v;
                return;
            }
            down(cur);
            if (ql <= mid) uCvr(ls, l, mid, ql, qr, v);
            if (qr > mid) uCvr(rs, mid + 1, r, ql, qr, v);
            up(cur);
        }

        int qFree(int cur, int l, int r, int v) {
            if (l == r) return l;
            down(cur);
            if (tr[ls].sum >= v) return qFree(ls, l, mid, v);
            if (tr[ls].sufx + tr[rs].prex >= v) return mid - tr[ls].sufx + 1;
            return qFree(rs, mid + 1, r, v);
        }
        #undef lc
        #undef rc
        #undef mid
    } using namespace SGT;

    int main() {
        read(n, m);
        build(1, 1, n);
        rep(i, 1, m) {
            read(op);
            if (op == 1) {
                read(d);
                if (tr[1].sum >= d) {
                    ans = qFree(1, 1, n, d);
                    printf("%d\n", ans);
                    uCvr(1, 1, n, ans, ans + d - 1, -1);
                } else puts("0");
            } else {
                read(x, d);
                uCvr(1, 1, n, x, x + d - 1, 1);
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }

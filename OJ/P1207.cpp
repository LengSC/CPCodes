#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
    #define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)
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

    namespace SGT {
        #define lc (cur << 1)
        #define rc (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct {
            struct {
                int l, r, add, sum;
            } tr[800005];

            void down(int cur) {
                if (tr[cur].add) {
                    tr[lc].sum += tr[cur].add * (tr[lc].r - tr[lc].l + 1);
                    tr[rc].sum += tr[cur].add * (tr[rc].r - tr[rc].l + 1);
                    tr[lc].add += tr[cur].add;
                    tr[rc].add += tr[cur].add;
                    tr[cur].add = 0;
                }
            }

            void up(int cur) {
                tr[cur].sum = tr[lc].sum + tr[rc].sum;
            }

            void build(int cur, int l, int r) {
                tr[cur].l = l, tr[cur].r = r;
                tr[cur].add = tr[cur].sum = 0;
                if (l == r) return;
                build(lc, l, mid), build(rc, mid + 1, r);
            }

            void uAdd(int cur, int l, int r, int v) {
                if (tr[cur].r < l || tr[cur].l > r) return;
                if (l <= tr[cur].l && tr[cur].r <= r)
                    return tr[cur].sum += v * (tr[cur]. r - tr[cur].l + 1), tr[cur].add += v, void();
                down(cur);
                uAdd(lc, l, r, v), uAdd(rc, l, r, v);
                up(cur);
            }

            int qSum(int cur, int l, int r) {
                if (tr[cur].r < l || tr[cur]. l > r) return 0;
                if (l <= tr[cur].l && tr[cur].r <= r) return tr[cur].sum;
                down(cur);
                return qSum(lc, l, r) + qSum(rc, l, r);
            }
        } st;
    }

    int xc, n, l, r, c, p;

    int main() {
        read(xc, n);
        SGT::st.build(1, 1, 200000);
        rep(i, 1, n) {
            read(l, r, c);
            SGT::st.uAdd(1, l + 100001, r + 100000, 1);
        }
        read(p);
        printf("%d\n", SGT::st.qSum(1, p + 100001, p + 100001));
        return 0;
    }
}

int main() { return SLV::main(); }
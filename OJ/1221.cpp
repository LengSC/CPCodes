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

    constexpr int N = 1e5 + 2, INF = 0x3f3f3f3f;

    int n, m, a[N], x, y;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int sum, maxx, premax, sufmax, minn, premin, sufmin;
        } tr[N << 2];

        void up(int cur) {
            tr[cur].sum = tr[ls].sum + tr[rs].sum;
            tr[cur].maxx = max({tr[ls].maxx, tr[rs].maxx, tr[ls].sufmax + tr[rs].premax});
            tr[cur].premax = max(tr[ls].premax, tr[ls].sum + tr[rs].premax);
            tr[cur].sufmax = max(tr[rs].sufmax, tr[ls].sufmax + tr[rs].sum);
            tr[cur].minn = min({tr[ls].minn, tr[rs].minn, tr[ls].sufmin + tr[rs].premin});
            tr[cur].premin = min(tr[ls].premin, tr[ls].sum + tr[rs].premin);
            tr[cur].sufmin = min(tr[rs].sufmin, tr[ls].sufmin + tr[rs].sum);
        }

        void build(int cur, int l, int r) {
            if (l == r)
                return tr[cur].sum = tr[cur].maxx = tr[cur].premax = tr[cur].sufmax = tr[cur].minn = tr[cur].premin = tr[cur].sufmin = a[l], void();
            build(ls, l, mid), build(rs, mid + 1, r);
            up(cur);
        }

        void uSet(int cur, int l, int r, int x, int v) {
            if (l == r)
                return tr[cur].sum = tr[cur].maxx = tr[cur].premax = tr[cur].sufmax = tr[cur].minn = tr[cur].premin = tr[cur].sufmin = v, void();
            if (x <= mid) uSet(ls, l, mid, x, v);
            if (x > mid) uSet(rs, mid + 1, r, x, v);
            up(cur);
        }

        int qMaxsum(int cur, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return -INF;
            if (ql <= l && r <= qr) return tr[cur].maxx;
            return max({qMaxsum(ls, l, mid, ql, qr), qMaxsum(rs, mid + 1, r, ql, qr), tr[ls].sufmax + tr[rs].premax});
        }
        #undef ls
        #undef rs
        #undef mid
    }

    int main() {
        read(n);
        rep(i, 1, n) read(a[i]);
        SGT::build(1, 1, n);
        read(m);
        rep(i, 1, m) {
            read(x, y);
            SGT::uSet(1, 1, n, x, y);
            printf("%d\n", max({((x = SGT::tr[1].sum - SGT::tr[1].minn) == 0 ? -INF : x), SGT::qMaxsum(1, 1, n, 1, n - 1), SGT::qMaxsum(1, 1, n, 2, n)}));
        }
        return 0;
    }
}

int main() { return SLV::main(); }

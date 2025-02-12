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

    constexpr int N = 5e4 + 2;

    int a[N], n, q, l, r;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int maxx, minn;
        } tr[N << 2];

        Node operator+(const Node &ln, const Node &rn) {
            Node res;
            res.maxx = max(ln.maxx, rn.maxx);
            res.minn = min(ln.minn, rn.minn);
            return res;
        }

        void build(int cur, int l, int r) {
            if (l == r) return tr[cur] = {a[l], a[l]}, void();
            build(ls, l, mid), build(rs, mid + 1, r);
            tr[cur] = tr[ls] + tr[rs];
        }

        Node qry(int cur, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return tr[cur];
            if (qr <= mid) return qry(ls, l, mid, ql, qr);
            if (ql > mid) return qry(rs, mid + 1, r, ql, qr);
            return qry(ls, l, mid, ql, qr) + qry(rs, mid + 1, r, ql, qr);
        }
        #undef ls
        #undef rs
        #undef mid
    }

    SGT::Node t;

    int main() {
        read(n, q);
        rep(i, 1, n) read(a[i]);
        SGT::build(1, 1, n);
        rep(i, 1, q) {
            read(l, r);
            t = SGT::qry(1, 1, n, l, r);
            printf("%d\n", t.maxx - t.minn);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

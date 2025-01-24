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

    constexpr int N = 5e5 + 5;

    int n, m, op, x, y, a[N];

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int sum, mxsum, lms, rms;
        } tr[N << 2];

        Node operator+(const Node &a, const Node &b) {
            Node res;
            res.sum = a.sum + b.sum;
            res.mxsum = max({a.mxsum, b.mxsum, a.rms + b.lms});
            res.lms = max(a.lms, a.sum + b.lms);
            res.rms = max(b.rms, a.rms + b.sum);
            return res;
        }
        
        void build(int cur, int l, int r) {
            if (l == r) return tr[cur] = {a[l], a[l], a[l], a[l]}, void();
            build(ls, l, mid), build(rs, mid + 1, r);
            tr[cur] = tr[ls] + tr[rs];
        }

        void uSet(int cur, int l, int r, int x, int v) {
            if (l == r) return tr[cur] = {v, v, v, v}, void();
            if (x <= mid) uSet(ls, l, mid, x, v);
            if (x > mid) uSet(rs, mid + 1, r, x, v);
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

    int main() {
        read(n); rep(i, 1, n) read(a[i]); read(m);
        SGT::build(1, 1, n);
        rep(i, 1, m) {
            read(op, x, y);
            if (op == 0) SGT::uSet(1, 1, n, x, y);
            else printf("%d\n", SGT::qry(1, 1, n, x, y).mxsum);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

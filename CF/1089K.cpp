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

    constexpr int N = 1e6 + 5, Q = 3e5 + 5;

    int q, x, a[Q];
    char op[3];

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            ll sum, las;
        } tr[N << 2];

        Node operator +(const Node &a, const Node &b) {
            Node res;
            res.sum = a.sum + b.sum;
            res.las = max(a.las + b.sum, b.las);
            return res;
        }

        void modify(int cur, int l, int r, int x, int v) {
            if (l == r) return tr[cur].sum = v, tr[cur].las = x + v, void();
            if (x <= mid) modify(ls, l, mid, x, v);
            else modify(rs, mid + 1, r, x, v);
            tr[cur] = tr[ls] + tr[rs];
        }

        Node qry(int cur, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return tr[cur];
            if (qr < l || ql > r) return {0, 0};
            return qry(ls, l, mid, ql, qr) + qry(rs, mid + 1, r, ql, qr);
        }
        #undef ls
        #undef rs
        #undef mid
    }

    int main() {
        read(q);
        rep(i, 1, q) {
            switch(scanf("%s", op), op[0]) {
            case '+':
                read(a[i], x);
                SGT::modify(1, 1, N, a[i], x);
                break;
            case '-':
                read(x);
                if (a[x]) SGT::modify(1, 1, N, a[x], 0);
                break;
            case '?':
                read(x);
                printf("%lld\n", max(0ll, SGT::qry(1, 1, N, 1, x).las - x));
                break;
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }

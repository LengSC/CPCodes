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

    constexpr int N = 1e5 + 5;

    int T, n, m, a[N], l1, r1, l2, r2, ans;

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

    void solve() {
        read(n); rep(i, 1, n) read(a[i]); read(m);
        SGT::build(1, 1, n);
        rep(i, 1, m) {
            read(l1, r1, l2, r2);
            if (r1 < l2)
                ans = SGT::qry(1, 1, n, l1, r1).rms + SGT::qry(1, 1, n, l2, r2).lms + (l2 - r1 == 1 ? 0 : SGT::qry(1, 1, n, r1 + 1, l2 - 1).sum);
            else {
				ans = 0xc0c0c0c0;
				if (l1 < l2) ans = max(ans, SGT::qry(1, 1, n, l1, l2 - 1).rms + SGT::qry(1, 1, n, l2, r2).lms);
				if (r1 < r2) ans = max(ans, SGT::qry(1, 1, n, l1, r1).rms + SGT::qry(1, 1, n, r1 + 1, r2).lms);
				ans = max(ans, SGT::qry(1, 1, n, l2, r1).mxsum);
			}
            printf("%d\n", ans);
        }
    }

    int main() {
        for (read(T); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 5e5 + 2, INF = 0x3f3f3f3f;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int minn;
            Node(): minn(INF) {}
        } tr[N << 2];

        void up(int cur) {
            tr[cur].minn = min(tr[ls].minn, tr[rs].minn);
        }

        void uSet(int cur, int l, int r, int pos, int v) {
            if (l == r) return tr[cur].minn = v, void();
            if (pos <= mid) uSet(ls, l, mid, pos, v);
            else uSet(rs, mid + 1, r, pos, v);
            up(cur);
        }

        int qMin(int cur, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return tr[cur].minn;
            if (qr < l || ql > r) return INF;
            return min(qMin(ls, l, mid, ql, qr), qMin(rs, mid + 1, r, ql, qr));
        }
        #undef ls
        #undef rs
        #undef mid
    }

    int n, m, a[N], mp[N], tot, now, pre[N];
    struct Query { int l, r, ans, id; } q[N];

    int main() {
        read(n, m);
        rep(i, 1, n) read(a[i]), mp[i] = a[i];
        sort(mp + 1, mp + 1 + n);
        tot = unique(mp + 1, mp + 1 + n) - mp - 1;
        rep(i, 1, n) a[i] = lower_bound(mp + 1, mp + 1 + tot, a[i]) - mp;
        rep(i, 1, m) read(q[i].l, q[i].r), q[i].ans = INF, q[i].id = i;
        sort(q + 1, q + 1 + m, [](const Query &a, const Query &b) { return a.r < b.r; });
        rep(i, 1, m) {
            rep(j, q[i - 1].r + 1, q[i].r) {
                if (pre[a[j]]) SGT::uSet(1, 1, n, pre[a[j]], j - pre[a[j]]);
                pre[a[j]] = j;
            }
            q[i].ans = SGT::qMin(1, 1, n, q[i].l, q[i].r);
        }
        sort(q + 1, q + 1 + m, [](const Query &a, const Query &b) { return a.id < b.id; });
        rep(i, 1, m) printf("%d\n", q[i].ans == INF ? -1 : q[i].ans);
        return 0;
    }
}

int main() { return SLV::main(); }

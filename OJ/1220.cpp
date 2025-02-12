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

    constexpr int N = 1e5 + 2;

    int n, q, a[N], x, y, l[N], r[N], pos[N], cnt[N], tot, ans;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int maxn;
        } tr[N << 2];

        void build(int cur, int l, int r) {
            if (l == r) return tr[cur].maxn = cnt[l], void();
            build(ls, l, mid), build(rs, mid + 1, r);
            tr[cur].maxn = max(tr[ls].maxn, tr[rs].maxn);
        }

        int qry(int cur, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return tr[cur].maxn;
            if (qr <= mid) return qry(ls, l, mid, ql, qr);
            if (ql > mid) return qry(rs, mid + 1, r, ql, qr);
            return max(qry(ls, l, mid, ql, qr), qry(rs, mid + 1, r, ql, qr));
        }
        #undef ls
        #undef rs
        #undef mid
    }

    int main() {
        read(n, q);
        rep(i, 1, n) read(a[i]);
        l[1] = 1, r[1] = 1, pos[1] = 1, cnt[1] = 1, tot = 1;
        rep(i, 2, n) {
            if (a[i] == a[i - 1]) r[tot] = i;
            else l[++tot] = i, r[tot] = i;
            pos[i] = tot;
            ++cnt[tot];
        }
        SGT::build(1, 1, tot);
        rep(i, 1, q) {
            read(x, y);
            if (x > y) swap(x, y);
            if (pos[x] == pos[y]) ans = y - x + 1;
            else if (pos[x] + 1 == pos[y]) ans = max(r[pos[x]] - x + 1, y - l[pos[y]] + 1);
            else ans = max({r[pos[x]] - x + 1, y - l[pos[y]] + 1, SGT::qry(1, 1, tot, pos[x] + 1, pos[y] - 1)});
            printf("%d\n", ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

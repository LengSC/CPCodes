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

    constexpr int N = 1002;

    double s[N << 3];
    int n, t, tot;
    double x1, y1, x2, y2, ans;

    namespace SGT {
        #define ls (cur * 2)
        #define rs (cur * 2 + 1)
        #define mid ((l + r) / 2)
        struct {
            int l, r, cnt;
            double sum;
        } tr[N << 3];

        void up(int cur) {
            if (tr[cur].cnt) tr[cur].sum = s[tr[cur].r + 1] - s[tr[cur].l];
            else tr[cur].sum = tr[ls].sum + tr[rs].sum;
        }

        void build(int cur, int l, int r) {
            tr[cur].l = l, tr[cur].r = r, tr[cur].cnt = tr[cur].sum = 0;
            if (l == r) return;
            build(ls, l, mid);
            build(rs, mid + 1, r);
        }

        void update(int cur, double l, double r, int flg) {
            if (s[tr[cur].r + 1] <= l || r <= s[tr[cur].l]) return;
            if (l <= s[tr[cur].l] && s[tr[cur].r + 1] <= r) tr[cur].cnt += flg;
            else update(ls, l, r, flg), update(rs, l, r, flg);
            up(cur);
        }
    }

    struct Coor {
        double l, r, h;
        int flg;
        bool operator <(const Coor &b) const {
            return h < b.h;
        }
    } p[N << 3];

    int main() {
        while (read(n), n) {
            ans = 0;
            rep(i, 1, n) {
                scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
                s[i * 2 - 1] = x1;
                s[i * 2] = x2;
                p[i * 2 - 1] = {x1, x2, y1, 1};
                p[i * 2] = {x1, x2, y2, -1};
            }
            n *= 2;
            sort(s + 1, s + 1 + n);
            sort(p + 1, p + 1 + n);
            tot = unique(s + 1, s + 1 + n) - s - 1;
            SGT::build(1, 1, tot - 1);
            rep(i, 1, n - 1) {
                SGT::update(1, p[i].l, p[i].r, p[i].flg);
                ans += (p[i + 1].h - p[i].h) * SGT::tr[1].sum;
            }
            printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++t, ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

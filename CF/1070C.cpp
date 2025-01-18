#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    using pll = pair<ll, ll>;
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

    constexpr int N = 1e6 + 2;

    struct Plan {
        ll t, c, p;
    } pl[N << 1];

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            ll cnt, sum;
        } tr[N << 2];

        void up(int cur) {
            tr[cur].cnt = tr[ls].cnt + tr[rs].cnt;
            tr[cur].sum = tr[ls].sum + tr[rs].sum;
        }

        void modify(int cur, int l, int r, int x) {
            if (l == r) {
                tr[cur].cnt += pl[x].c;
                tr[cur].sum += pl[x].c * pl[x].p;
                return;
            }
            if (pl[x].p <= mid) modify(ls, l, mid, x);
            else modify(rs, mid + 1, r, x);
            up(cur);
        }

        pll qry(int cur, int l, int r, ll num) {
            if (l == r) {
                pll res;
                if (tr[cur].cnt == num) res.first = l;
                else res.first = l - 1, res.second = l * num;
                return res;
            }
            if (tr[cur].cnt == num) return make_pair(r, 0);
            if (tr[ls].cnt >= num) return qry(ls, l, mid, num);
            return qry(rs, mid + 1, r, num - tr[ls].cnt);
        }

        ll qSum(int cur, int l, int r, int ql, int qr) {
            if (qr < l || ql > r) return 0;
            if (ql <= l && r <= qr) return tr[cur].sum;
            return qSum(ls, l, mid, ql, qr) + qSum(rs, mid + 1, r, ql, qr);
        }
    }

    ll n, k, m, maxp, dlt, ans, res;
    pll r;

    int main() {
        read(n, k, m);
        rep(i, 1, m) {
            read(pl[i * 2 - 1].t, pl[i * 2].t, pl[i * 2 - 1].c, pl[i * 2 - 1].p);
            ++pl[i * 2].t;
            pl[i * 2].c = -pl[i * 2 - 1].c;
            pl[i * 2].p = pl[i * 2 - 1].p;
            maxp = max(maxp, pl[i * 2].p);
        }
        sort(pl, pl + m * 2 + 1, [](const Plan &a, const Plan &b) {
            return a.t < b.t;
        });
        SGT::modify(1, 1, maxp, 1);
        rep(i, 2, m * 2) {
            dlt = pl[i].t - pl[i - 1].t;
            if (SGT::tr[1].cnt < k) ans += SGT::tr[1].sum * dlt;
            else {
                r = SGT::qry(1, 1, maxp, k);
                res = r.second;
                if (r.first) res += SGT::qSum(1, 1, maxp, 1, r.first);
                ans += res * dlt;
            }
            SGT::modify(1, 1, maxp, i);
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

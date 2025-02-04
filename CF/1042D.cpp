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

    constexpr ll N = 2e5 + 5, M = 1e7, OFS = 1e15, RANGE = 2e15;

    ll n, t, pre[N], ans;

    namespace SGT {
        #define ls (tr[cur].lson)
        #define rs (tr[cur].rson)
        #define mid ((l + r) >> 1)
        struct Node {
            ll sum, lson, rson;
        } tr[M];

        ll root = 0, tot = 0;
        void newNode(ll &cur) { if (!cur) cur = ++tot; }

        void insert(ll &cur, ll l, ll r, ll x) {
            newNode(cur);
            if (l == r) return ++tr[cur].sum, void();
            if (x <= mid) insert(ls, l, mid, x);
            else insert(rs, mid + 1, r, x);
            tr[cur].sum = tr[ls].sum + tr[rs].sum;
        }

        ll qry(ll cur, ll l, ll r, ll ql, ll qr) {
            if (ql <= l && r <= qr) return tr[cur].sum;
            if (qr < l || ql > r) return 0;
            return qry(ls, l, mid, ql, qr) + qry(rs, mid + 1, r, ql, qr);
        }
        #undef ls
        #undef rs
        #undef mid
    }

    /**
     *    sum[l ~ r] < t
     * => pre[r] - pre[l - 1] < t
     * => pre[r] < pre[l - 1] + t
     */

    int main() {
        read(n, t);
        rep(i, 1, n) read(pre[i]), pre[i] += pre[i - 1];
        per(i, n, 1)
            SGT::insert(SGT::root, 1, RANGE, pre[i] + OFS),
            ans += SGT::qry(SGT::root, 1, RANGE, 1, pre[i - 1] + OFS + t - 1);
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

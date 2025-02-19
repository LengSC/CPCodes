#include <bits/stdc++.h>

namespace SLV {
#define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
#define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
#define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

constexpr int N = 1e5 + 2, OFS = 1e5;

int n, m, a[N], ql, qr, pre[N * 2];
vector<pii> q[N];
ll ans[N];

namespace SEG {
    #define ls (cur << 1)
    #define rs (cur << 1 | 1)
    #define mid ((l + r) >> 1)
    struct Node {
        ll ms, hms, add, hma;
        /**
         * ms:  max substring sum
         * hms: history max ms
         * add: lazytag for add
         * hma: history max add
         */
    } tr[N << 2];

    void down(int cur) {
        tr[ls].hms = max(tr[ls].hms, tr[ls].ms + tr[cur].hma);
        tr[ls].ms += tr[cur].add;
        tr[ls].hma = max(tr[ls].hma, tr[ls].add + tr[cur].hma);
        tr[ls].add += tr[cur].add;
        tr[rs].hms = max(tr[rs].hms, tr[rs].ms + tr[cur].hma);
        tr[rs].ms += tr[cur].add;
        tr[rs].hma = max(tr[rs].hma, tr[rs].add + tr[cur].hma);
        tr[rs].add += tr[cur].add;
        tr[cur].add = tr[cur].hma = 0;
    }

    void up(int cur) {
        tr[cur].ms = max(tr[ls].ms, tr[rs].ms);
        tr[cur].hms = max(tr[ls].hms, tr[rs].hms);
    }

    void uAdd(int cur, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr)
            return tr[cur].hms = max(tr[cur].hms, tr[cur].ms += val),
                   tr[cur].hma = max(tr[cur].hma, tr[cur].add += val), void();
        down(cur);
        uAdd(ls, l, mid, ql, qr, val), uAdd(rs, mid + 1, r, ql, qr, val);
        up(cur);
    }

    ll qHms(int cur, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tr[cur].hms;
        down(cur);
        return max(qHms(ls, l, mid, ql, qr), qHms(rs, mid + 1, r, ql, qr));
    }
    #undef ls
    #undef rs
    #undef mid
}

int main() {
    read(n);
    rep(i, 1, n) read(a[i]);
    read(m);
    rep(i, 1, m) read(ql, qr), q[qr].eb(ql, i);
    rep(r, 1, n) {
        SEG::uAdd(1, 1, n, pre[a[r] + OFS] + 1, r, a[r]);
        for (auto qry: q[r]) ans[qry.se] = SEG::qHms(1, 1, n, qry.fi, r);
        pre[a[r] + OFS] = r;
    }
    rep(i, 1, m) printf("%lld\n", ans[i]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

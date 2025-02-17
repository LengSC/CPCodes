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

constexpr int N = 1e5 + 2;

ll n, m, l, r, now, s[N], x;
char op;

namespace PERSEG {
    #define ls(t) (tr[t].lson)
    #define rs(t) (tr[t].rson)
    #define mid ((l + r) / 2)
    struct Node {
        ll lson, rson, sum;
    } tr[N * 50];

    ll rt1[N], rt2[N], cnt;

    void modify(ll &cur, ll l, ll r, ll x, ll val) {
        tr[++cnt] = tr[cur], cur = cnt, tr[cur].sum += val;
        if (l == r) return;
        if (x <= mid) modify(ls(cur), l, mid, x, val);
        else modify(rs(cur), mid + 1, r, x, val);
    }

    ll qry(ll cur, ll l, ll r, ll x) {
        if (l == r) return tr[cur].sum;
        if (x <= mid) return qry(ls(cur), l, mid, x);
        else return tr[ls(cur)].sum + qry(rs(cur), mid + 1, r, x);
    }

    ll qry(ll tick, ll x) {
        return s[x] + qry(rt1[tick], 1, n, x) * (x + 1) - qry(rt2[tick], 1, n, x);
    }
} using namespace PERSEG;

int main() {
    read(n, m);
    rep(i, 1, n) read(s[i]), s[i] += s[i - 1];
    rep(i, 1, m) {
        scanf(" %c", &op);
        switch (op) {
        case 'C':
            read(l, r, x);
            ++now;
            rt1[now] = rt1[now - 1];
            rt2[now] = rt2[now - 1];
            modify(rt1[now], 1, n, l, x);
            modify(rt1[now], 1, n, r + 1, -x);
            modify(rt2[now], 1, n, l, x * l);
            modify(rt2[now], 1, n, r + 1, -x * (r + 1));
            break;
        case 'Q':
            read(l, r);
            printf("%lld\n", qry(now, r) - qry(now, l - 1));
            break;
        case 'H':
            read(l, r, x);
            printf("%lld\n", qry(x, r) - qry(x, l - 1));
            break;
        case 'B':
            read(now);
            break;
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

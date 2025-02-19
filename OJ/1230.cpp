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

int n, m, op, l, r, t;
ll a[N];

namespace BIT {
    ll c[N];

    void build() {
        for (int i = 1, j; i <= n; ++i) {
            c[i] += a[i];
            j = i + (i & -i);
            if (j <= n) c[j] += c[i];
        }
    }

    void add(int x, ll val) { for (; x <= n; x += x & -x) c[x] += val; }

    ll qry(int x) {
        ll res = 0;
        for (; x; x ^= x & -x) res += c[x];
        return res;
    }

    ll qry(int l, int r) { return qry(r) - qry(l - 1); }
}

namespace DSU {
    int fa[N];

    void init() { iota(fa + 1, fa + 2 + n, 1); }

    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
}

int main() {
    read(n); rep(i, 1, n) read(a[i]);
    BIT::build(); DSU::init();
    read(m);
    rep(i, 1, m) {
        read(op, l, r);
        if (l > r) swap(l, r);
        if (op == 0) {
            while (l <= r) {
                BIT::add(l, (t = sqrt(a[l])) - a[l]);
                a[l] = t;
                DSU::fa[l] = (a[l] > 1) ? l : l + 1;
                l = (DSU::find(l) == l) ? l + 1 : DSU::fa[l];
            }
        } else printf("%lld\n", BIT::qry(l, r));
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

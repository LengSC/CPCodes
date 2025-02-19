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

int n, q, l, r, x;
char op;
ll a[N];

namespace BIT {
    ll c1[N], c2[N];

    void build() {
        for (int i = 1, j; i <= n; ++i) {
            c1[i] += (a[i] - a[i - 1]);
            c2[i] += (a[i] - a[i - 1]) * i;
            if ((j = i + (i & -i)) <= n) c1[j] += c1[i], c2[j] += c2[i];
        }
    }

    void add(int x, ll val) {
        for (ll xv = x * val; x <= n; x += x & -x)
            c1[x] += val, c2[x] += xv;
    }

    void add(int l, int r, ll val) { add(l, val), add(r + 1, -val); }

    ll qry(ll *c, int x) {
        ll res = 0;
        for (; x; x ^= x & -x) res += c[x];
        return res;
    }

    ll qry(int l, int r) {
        return (qry(c1, r) * (r + 1) - qry(c1, l - 1) * l) -
               (qry(c2, r) - qry(c2, l - 1));
    }
}

int main() {
    read(n, q);
    rep(i, 1, n) read(a[i]);
    BIT::build();
    rep(i, 1, q) {
        scanf(" %c", &op), read(l, r);
        if (op == 'Q') printf("%lld\n", BIT::qry(l, r));
        else read(x), BIT::add(l, r, x);
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

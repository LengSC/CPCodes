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

constexpr int N = 1e6 + 2;

int n, q, op, l, r, x;
ll a[N];

namespace BIT {
    ll c[N];

    void build() {
        for (int i = 1, j; i <= n; ++i) {
            c[i] += a[i] - a[i - 1];
            if ((j = i + (i & -i)) <= n) c[j] += c[i];
        }
    }

    void add(int x, ll val) { for (; x <= n; x += x & -x) c[x] += val; }

    ll qry(int x) {
        ll res = 0;
        for (; x; x ^= x & -x) res += c[x];
        return res;
    }
}

int main() {
    read(n, q); rep(i, 1, n) read(a[i]);
    BIT::build();
    rep(i, 1, q) {
        read(op, l);
        if (op == 1) {
            read(r, x);
            BIT::add(l, x);
            BIT::add(r + 1, -x);
        } else printf("%lld\n", BIT::qry(l));
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

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

int n, l, r;

namespace BIT {
    int tick, tk[N];
    ll c[N];

    void clear() { ++tick; }

    void add(int x, int val) {
        for (; x <= n; x += x & -x) {
            if (tk[x] != tick) c[x] = 0;
            c[x] += val;
            tk[x] = tick;
        }
    }

    ll qry(int x) {
        ll res = 0;
        for (; x; x ^= x & -x) res += (tk[x] == tick ? c[x] : 0);
        return res;
    }
}

int main() {
    while (read(n), n) {
        rep(i, 1, n) {
            read(l, r);
            BIT::add(l, 1);
            BIT::add(r + 1, -1);
        }
        rep(i, 1, n) printf("%lld%c", BIT::qry(i), " \n"[i == n]);
        BIT::clear();
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

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

int n, m, k, x1, x2, v, mp[1002][2002], ans;

int main() {
    read(n, m);
    rep(i, 1, m) {
        read(k, x1, x2, v);
        if (k == 1) rep(i, x1, x2) rep(j, 1, v) ++mp[i][j];
        else {
            ans = 0;
            rep(i, x1, x2) rep(j, 1, v) ans += mp[i][j], mp[i][j] = 0;
            printf("%d\n", ans);
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

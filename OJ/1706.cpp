#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define fi first
    #define se second
    using namespace std;
    using ll = long long;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 5005;

    int n, l, f[N];
    pii a[N];

    int main() {
        read(n);
        rep(i, 1, n) read(a[i].fi, a[i].se);
        sort(a + 1, a + 1 + n, greater<pii>());
        rep(i, 1, n)
            if (f[l] < a[i].se) f[++l] = a[i].se;
            else *lower_bound(f, f + 1 + l, a[i].se) = a[i].se;
        printf("%d\n", l);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 2005;
    
    int n, f1[N], f2[N], *p;
    pii a[N];

    int main() {
        read(n);
        rep(i, 1, n) read(a[i].fi, a[i].se);
        sort(a + 1, a + 1 + n);
        rep(i, 1, n) {
            if (a[i].se >= f1[f1[0]]) f1[++f1[0]] = a[i].se;
            else {
                p = upper_bound(f1 + 1, f1 + 1 + f1[0], a[i].se);
                if (*p >= f2[f2[0]]) f2[++f2[0]] = *p;
                else *upper_bound(f2 + 1, f2 + 1 + f2[0], *p) = *p;
                *p = a[i].se;
            }
        }
        printf("%d\n", f1[0] + f2[0]);
        return 0;
    }
}

int main() { return SLV::main(); }

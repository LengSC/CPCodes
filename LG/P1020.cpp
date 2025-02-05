#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 1e5 + 5;

    int n, a[N], f1[N], l1, f2[N], l2;

    int main() {
        while (~scanf("%d", &a[++n]));
        rep(i, 1, n) {
            if (a[i] <= f1[l1]) f1[++l1] = a[i];
            else *upper_bound(f1, f1 + 1 + l1, a[i], greater<int>()) = a[i];
            if (a[i] > f2[l2]) f2[++l2] = a[i];
            else *lower_bound(f2, f2 + 1 + l2, a[i]) = a[i];
        }
        printf("%d\n%d\n", l1, l2);
        return 0;
    }
}

int main() { return SLV::main(); }

#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    namespace IO {
        template<typename T>
        void read(T &x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    int n, lim;
    double p[(1 << 20) + 5], ans;

    int main() {
        read(n);
        lim = (1 << n) - 1;
        rep(i, 0, lim) scanf("%lf", &p[i]);
        /* FMT???
        for (int k = 1; k <= lim; k <<= 1)
            for (int s = 0; s <= lim; s += k << 1)
                dep(i, s, s + k) p[i + k] += p[i];
        */
        dep(i, 0, n) rep(j, 0, lim)
            if (j & (1 << i)) p[j] += p[j ^ (1 << i)];
        rep(i, 1, lim) {
            if (1 - p[lim ^ i] < 1e-9) return puts("INF"), 0;
            ans += (__builtin_popcount(i) & 1 ? 1 : -1) / (1 - p[lim ^ i]);
        }
        printf("%lf\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

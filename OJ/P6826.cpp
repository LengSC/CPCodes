#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
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

    constexpr int N = 22;

    int n;
    double p[N], ans, sump;

    void solve() {
        rep(i, 1, n) scanf("%lf", &p[i]);
        ans = 0;
        rep(s, 1, (1 << n) - 1) {
            sump = 0;
            rep(i, 1, n) if (s & (1 << (i - 1))) sump += p[i];
            ans += (__builtin_popcount(s) & 1 ? 1 : -1) / sump;
        }
        printf("%lf\n", ans);
    }

    int main() {
        while (~scanf("%d", &n)) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

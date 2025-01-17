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

    constexpr int N = 1e5 + 2;

    int c[5], tot, d[5], s, tmp;
    ll f[N], ans;
    bool flg;

    void solve() {
        rep(i, 1, 4) read(d[i]); read(s);
        ans = 0;
        rep(i, 0, (1 << 4) - 1) {
            tmp = s, flg = false;
            rep(j, 1, 4) if ((i >> (j - 1)) & 1) tmp -= c[j] * (d[j] + 1), flg ^= true;
            if (tmp < 0) continue;
            ans += (flg ? -f[tmp] : f[tmp]);
        }
        printf("%lld\n", ans);
    }

    void pre() {
        rep(i, 1, 4) read(c[i]); read(tot);
        f[0] = 1;
        rep(i, 1, 4) rep(j, c[i], N - 1) f[j] += f[j - c[i]];
    }

    int main() {
        for (pre(); tot; --tot) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

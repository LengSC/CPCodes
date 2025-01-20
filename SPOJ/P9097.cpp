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

    constexpr int N = 16;

    ll t, n, a[N], cnt[N], cur[N], siz, fac[N], ans, tmp;

    void solve() {
        read(n);
        memset(cnt, 0, sizeof(cnt));
        rep(i, 1, n) read(a[i]), ++cnt[a[i]];
        ans = 0;
        rep(i, 0, (1 << n) - 1) {
            memcpy(cur, cnt, sizeof(cur));
            siz = __builtin_popcount(i);
            tmp = fac[n - siz];
            rep(j, 0, n - 1) cur[a[j + 1]] -= ((i >> j) & 1);
            rep(j, 0, n - 1) tmp /= fac[cur[j]];
            ans += (siz & 1) ? -tmp : tmp;
        }
        printf("%lld\n", ans);
    }

    int main() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i;
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

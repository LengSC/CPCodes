#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    using ull = unsigned ll;
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

    constexpr ull N = 1e5 + 5, MOD = 1e9 + 7;

    ll n, k, a[N][7], c[7][7], siz, ans;
    unordered_map<ll, ll> mp;

    /* S_g(k) = \sum \limits_{siz = k}^{n}{(-1)^{siz - k} \cdot \binom{siz}{k} \cdot S_f(siz)} */

    int main() {
        read(n, k);
        rep(i, 1, n) rep(j, 1, 6) read(a[i][j]);
        rep(i, 0, 6) c[i][0] = 1;
        rep(i, 1, 6) rep(j, 1, i) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        rep(s, 0, (1 << 6) - 1) {
            mp.clear();
            if ((siz = __builtin_popcount(s)) >= k)
                rep(i, 1, n) {
                    ull hash = 0;
                    rep(j, 1, 6)
                        if (s & (1 << (j - 1)))
                            hash = hash * MOD + a[i][j];
                    ans += (mp[hash]++) * c[siz][k] * ((siz - k) & 1 ? -1 : 1);
                }
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

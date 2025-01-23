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

    constexpr int N = 18, M = 310, MOD = 1e9 + 7;

    int n, m, tu, tv, g[N], lim, f[1 << N], ans, pow2[M], cnt[1 << N], ed[1 << N];

    int main() {
        read(n, m);
        rep(i, 1, m) read(tu, tv), g[--tu] |= (1 << (--tv));
        lim = (1 << n) - 1, f[0] = 1, pow2[0] = 1;
        rep(i, 1, m) pow2[i] = (pow2[i - 1] << 1) % MOD;
        dep(s1, 0, lim) {
            if (!f[s1]) continue;
            dep(i, 0, n) cnt[1 << i] = 0;
            dep(i, 0, n) if (s1 & (1 << i))
                dep(j, 0, n) cnt[1 << j] += (g[i] >> j) & 1;
            for (int s2 = lim ^ s1, t = (s2 - 1) & s2, s; ; t = (t - 1) & s2) {
                s = s2 ^ t;
                ed[s] = ed[s ^ (s & -s)] + cnt[s & -s];
                f[s1 | s] = (f[s1 | s] + (ll)f[s1] * pow2[ed[s]] * (__builtin_popcount(s) & 1 ? 1 : -1)) % MOD;
                if (!t) break;
            }
        }
        printf("%lld\n", (f[lim] + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int M = 1 << 20, MOD = 1e9 + 7;

    ll n, m, k, t, s, ans, pow2[M], f[M];

    int main() {
        pow2[0] = 1;
        rep(i, 1, M - 1) pow2[i] = pow2[i - 1] * 2 % MOD;
        read(n, m);
        rep(i, 1, n) {
            for (read(k); k; --k) read(t), s |= 1 << (t - 1);
            ++f[s], s = 0;
        }
        rep(i, 0, m - 1) rep(j, 0, (1 << m) - 1) if (j & (1 << i)) f[j] += f[j ^ (1 << i)];
        rep(i, 0, (1 << m) - 1) ans = (ans + ((m - __builtin_popcount(i)) & 1 ? -1 : 1) * (pow2[f[i]] - 1)) % MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

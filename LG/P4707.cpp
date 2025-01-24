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

    constexpr int M = 1e4 + 5, K = 12, MOD = 998244353;

    ll n, m, s, ans, p, f[K][M];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    int main() {
        read(n, s, m); s = n - s + 1;
        f[0][0] = 1;
        rep(i, 1, n) {
            read(p);
            if (p) per(j, m, p)
                per(k, s, 1)
                    (f[k][j] += (f[k - 1][j - p] - f[k][j - p])) %= MOD;
        }
        rep(i, 1, m)
            (ans += f[s][i] * fpow(i, MOD - 2)) %= MOD;
        printf("%lld\n", (ans * m % MOD + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 1e7 + 1, MOD = 1e9 + 7;

    int t, q, a, b, c, d[N], e[N], f[N], g[N], np[N], pr[N], tot, ans1, ans2;
    /**
     * d[i]: i除去最小质因子的商
     * e[i]: i的最小质因子的指数
     * f[i]: i的约数平方和
     * g[i]: i的约数个数
     */

    int main() {
        f[1] = g[1] = 1;
        dep(i, 2, N) {
            if (!np[i]) {
                pr[++tot] = i;
                d[i] = e[i] = 1;
                f[i] = ((ll)i * i + 1) % MOD;
                g[i] = 2;
            }
            for (int j = 1, k; j <= tot && (k = i * pr[j]) < N; ++j) {
                np[k] = true;
                if (i % pr[j] == 0) {
                    d[k] = d[i];
                    e[k] = e[i] + 1;
                    f[k] = ((ll)f[i] * pr[j] % MOD * pr[j] % MOD + f[d[i]]) % MOD;
                    g[k] = g[i] / (e[i] + 1) * (e[k] + 1);
                    break;
                } else {
                    d[k] = i;
                    e[k] = 1;
                    f[k] = f[i] * ((ll)pr[j] * pr[j] + 1) % MOD;
                    g[k] = g[i] * 2;
                }
            }
        }
        for (read(t, q, a, b, c), a %= c, b %= c; t; --t, q = ((ll)q * a + b) % c + 1) {
            (ans1 += g[q] + (q & 1)) %= MOD;
            (ans2 += f[q] + 4 * (q & 1)) %= MOD;
        }
        printf("%d\n%d\n", ans1, ans2);
        return 0;
    }
}

int main() { return SLV::main(); }

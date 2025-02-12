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

    constexpr int N = 1002, MOD = 1e9 + 7;

    ll n, m, a[N], c[N * 2][N * 2], sign = 1, ans, tmp;

    int main() {
        read(n, m);
        rep(i, 1, m) read(a[i]);
        rep(i, 0, N * 2 - 1) c[i][0] = 1;
        rep(i, 1, N * 2 - 1) rep(j, 1, i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        // total = \prod_{i = 1}^{m}{C_{n + a_i - 1}^{n - 1}} = \sum_{i = 0}^{0}{(-1)^iC_n^i\prod_{j = 1}^{m}{C_{n + a_j - i - 1}^{n - i - 1}}}
        // illegal = \sum_{i = 1}^{n}{(-1)^iC_n^i\prod_{j = 1}^{m}{C_{n + a_j - i - 1}^{n - i - 1}}}
        // ans = total - illegal
        //     = \sum_{i = 0}^{n}{(-1)^iC_n^i\prod_{j = 1}^{m}{C_{n + a_j - i - 1}^{n - i - 1}}}
        rep(i, 0, n) {
            tmp = c[n][i];
            rep(j, 1, m) tmp = tmp * c[n + a[j] - i - 1][n - i - 1] % MOD;
            ans = (ans + sign * tmp % MOD) % MOD;;
            sign = -sign;
        }
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

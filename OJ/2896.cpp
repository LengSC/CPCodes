#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (int i = st, e##i = ed; i >= e##i; --i)

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
}
using namespace IO;

namespace SLV {
    constexpr int N = 1e5 + 2, MOD = 5000011;
    int n, k, f[N][2];
    int main() {
        read(n, k);
        f[1][0] = f[1][1] = 1;
        rep(i, 2, n) {
            f[i][0] = (i - k - 1 >= 1) ? (f[i - k - 1][0] + f[i - k - 1][1]) % MOD : 1;
            f[i][1] = (f[i - 1][0] + f[i - 1][1]) % MOD;
        }
        printf("%d\n", (f[n][0] + f[n][1]) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }
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
    constexpr int N = 2e3 + 2, MOD = 998244353;
    int n, k, x[N], y[N];

    int inv(int a) {
        int res = 1;
        for (int e = MOD - 2; e; e >>= 1, a = (ll)a * a % MOD)
            if (e & 1) res = (ll)res * a % MOD;
        return res;
    }

    int lagr(int n, int k, int *x, int *y) {
        int res = 0;
        rep(i, 1, n) {
            int a = 1, b = 1;
            rep(j, 1, n) {
                if (i != j) {
                    a = (ll)a * (k - x[j]) % MOD;
                    b = (ll)b * (x[i] - x[j]) % MOD;
                }
            }
            res = ((ll)res + (ll)y[i] * a % MOD * inv(b) % MOD) % MOD; 
        }
        return (res % MOD + MOD) % MOD;
    }

    int main() {
        read(n, k);
        rep(i, 1, n) read(x[i], y[i]);
        printf("%d\n", lagr(n, k, x, y));
        return 0;
    }
}

int main() { return SLV::main(); }
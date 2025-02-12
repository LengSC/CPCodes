#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
#define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)

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
    constexpr int N = 4e4 + 2;
    int n, phi[N], fc[N], pr[N], cnt;

    int solve(int n) {
        /* ans <- sigma(i, 1, n - 1){phi(i)} */
        phi[1] = 1;
        rep(i, 2, n) {
            if (!fc[i]) {
                pr[++cnt] = i;
                fc[i] = i;
                phi[i] = i - 1;
            }
            rep(j, 1, cnt) {
                if (pr[j] * i > n || pr[j] > fc[i]) break;
                fc[pr[j] * i] = pr[j];
                if (pr[j] < fc[i]) phi[pr[j] * i] = (pr[j] - 1) * phi[i];
                else phi[pr[j] * i] = pr[j] * phi[i];
            }
            phi[i] += phi[i - 1];
        }
        return phi[n] << 1 | 1;
    }

    int main() {
        read(n);
        printf("%d\n", solve(n));
        return 0;
    }
}

int main() { return SLV::main(); }
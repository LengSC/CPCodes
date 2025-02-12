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
    constexpr int N = 10;
    ll k, b[N], m[N];

    void exgcd(ll a, ll b, ll &x, ll &y) {
        if (!b) return x = 1, y = 0, void();
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }

    ll crt(int k, ll *b, ll *m) {
        ll M = 1, res = 0, Mi, invmi, y;
        rep(i, 1, k) M *= m[i];
        rep(i, 1, k) {
            Mi = M / m[i];
            exgcd(Mi, m[i], invmi, y); /* M*x === 1 (% m[i]) */
            res = (res + b[i] * Mi * invmi) % M;
        }
        return (res % M + M) % M;
    }

    int main() {
        read(k);
        rep(i, 1, k) read(b[i], m[i]);
        printf("%lld\n", crt(k, b, m));
        return 0;
    }
}

int main() { return SLV::main(); }
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
    constexpr int N = 1e5 + 2;
    int n; ll ai[N], bi[N];

    ll smul(ll a, ll b, ll m) {
        ll res = 0;
        for (; b; b >>= 1, a = (a + a) % m)
            if (b & 1) res = (res + a) % m;
        return res;
    }

    ll exgcd(ll a, ll b, ll &x, ll &y) {
        if (!b) return x = 1, y = 0, a;
        ll d = exgcd(b, a % b, x, y), t = x;
        x = y;
        y = t - a / b * y;
        return d;
    }

    ll excrt() {
        ll x, y, k, M = bi[1], res = ai[1];
        rep(i, 2, n) {
            ll a = M, b = bi[i], c = (ai[i] - res % b + b) % b; // ax===c(mod b)
            ll d = exgcd(a, b, x, y), bd = b / d;
            if (c % d) return -1;
            x = smul(x, c / d, bd);
            res += x * M;
            M *= bd;
            res = (res % M + M) % M;
        }
        return (res % M + M) % M;
    }

    int main() {
        read(n);
        rep(i, 1, n) read(bi[i], ai[i]);
        printf("%lld\n", excrt());
        return 0;
    }
}

int main() { return SLV::main(); }
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
    ll c1, c2, e1, e2, n, T;

    ll smul(ll a, ll b) {
        ll res = 0;
        for (; b; a = (a + a) % n, b >>= 1)
            if (b & 1) res = (res + a) % n;
        return res;
    }

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; a = smul(a, a), b >>= 1)
            if (b & 1) res = smul(res, a);
        return res;
    }

    ll exgcd(ll a, ll b, ll &x, ll &y) {
        if (!b) return x = 1, y = 0, a;
        ll d = exgcd(b, a % b, x, y);
        ll t = x;
        x = y;
        y = t - a / b * y;
        return d;
    }

    ll inv(ll a, ll b) {
        ll x, y, d = exgcd(a, b, x, y);
        return d == 1 ? (x % b + b) % b : -1;
    }

    void solve() {
        read(c1, c2, e1, e2, n);
        ll s, t;
        exgcd(e1, e2, s, t);
        if (s < 0) c1 = inv(c1, n), s = -s;
        if (t < 0) c2 = inv(c2, n), t = -t;
        printf("%lld\n", smul(fpow(c1, s), fpow(c2, t)));
    }

    int main() {
        for (read(T); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

/* (mod N)
c1 === m^e1
c2 === m^e2
let s, t <- e1*s + e2*t == gcd(e1, e2) == 1
m^1 === m^(e1*S + e2*t) === c1^s * c2^t
*/
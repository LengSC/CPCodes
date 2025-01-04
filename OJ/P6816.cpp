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
    ll T, n, m, p;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % p) if (b & 1) res = res * a % p;
        return res;
    }

    ll c(ll n, ll m) {
        ll sum = 1, inv = 1;
        rep(i, 1, m) {
            sum = sum * (n - i + 1) % p;
            inv = inv * i % p;
        }
        return sum * fpow(inv, p - 2) % p;
    }

    ll lucas(ll n, ll m) {
        if (!m) return 1;
        return lucas(n / p, m / p) * c(n % p, m % p) % p;
    }

    int main() {
        for(read(T); T; --T) {
            read(n, m, p);
            printf("%d\n", lucas(n + m, n));
        }
        return 0;
    }
}

int main() { return SLV::main(); }
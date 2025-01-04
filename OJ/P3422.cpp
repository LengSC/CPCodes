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
    constexpr int MOD = 1000000007;
    ll n, m, ans, c = 1;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD; 
        return res;
    }

    int main() {
        read(n, m);
        if (n > m) swap(n, m);
        /* ans = m + \sum_{i = 0}^{n}{C^i_{m + i}} */
        rep(i, 0, n) {
            ans = (ans + c) % MOD;
            c = (c * (m + i + 1) % MOD * fpow(i + 1, MOD - 2)) % MOD;
        }
        printf("%lld\n", (ans + m) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }
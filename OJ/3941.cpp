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

    ll n, k, m, p;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % p) if (b & 1) res = res * a % p;
        return res;
    }

    int main() {
        read(n, k, m, p);
        // ans = n * m^(k-1) - m^(k-2) * (k-1) * (m+1) * m / 2
        printf("%lld\n", ((n % p * fpow(m, k - 1) % p - fpow(m, k - 2) * (k - 1) % p * ((m + 1) * m / 2 % p) % p) % p + p) % p);
        return 0;
    }
}

int main() { return SLV::main(); }

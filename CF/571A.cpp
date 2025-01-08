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

    ll a, b, c, l, ans;

    ll get(ll x, ll y, ll z) {
        ll res = 0, rest;
        rep(i, max(0ll, x + y - z), l) {
            rest = min(l - i, z + i - x - y);
            res += (rest + 1) * (rest + 2) / 2;
        }
        return res;
    }

    int main() {
        read(a, b, c, l);
        rep(i, 0, l) ans += (ll)(i + 1) * (i + 2) / 2;
        ans -= (get(a, b, c) + get(a, c, b) + get(c, b, a));
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

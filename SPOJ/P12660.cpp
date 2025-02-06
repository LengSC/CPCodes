#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    using uint = unsigned int;
    using ll = long long;
    using ull = unsigned long long;
    using vi = vector<int>;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    int t;
    ll a, b, n, ans;

    int mu(int x) {
        int res = 1;
        rep(i, 2, sqrt(x)) {
            if (x % i == 0) {
                x /= i;
                if (x % i == 0) return 0;
                res = -res;
            }
        }
        return (x ^ 1) ? -res : res;
    }

    /**
     * Ans = \sum \limits_{d \mid n}{\mu(d) ([\frac{b}{d}] - [\frac{a - 1}{d}])}
     */

    int main() {
        read(t);
        rep(i, 1, t) {
            read(a, b, n), ans = 0, --a;
            rep(i, 1, sqrt(n)) {
                if (n % i) continue;
                ans += mu(i) * ((b / i) - (a / i));
                if (i * i != n) ans += mu(n / i) * (b / (n / i) - a / (n / i));
            }
            printf("Case #%d: %lld\n", i, ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

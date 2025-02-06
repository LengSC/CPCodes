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

    ll a, b, l, cnt1, cnt2, ans1, ans2, ans3;

    ll mu(ll x) {
        ll res = 1;
        rep(i, 2, sqrt(x)) {
            if (x % i == 0) {
                x /= i;
                if (x % i == 0) return 0;
                res = -res;
            }
        }
        return (x ^ 1) ? -res : res;
    }

    ll f(ll n, ll x) {
        ll res = 0;
        rep(d, 1, sqrt(x)) {
            if (x % d) continue;
            res += mu(d) * (n / d);
            if (d * d != x) res += mu(x / d) * (n / (x / d));
        }
        return res;
    }

    int main() {
        read(a, b, l);
        rep(i, -a, b) {
            cnt1 += f(l, a + i);
            cnt2 += f(l, b - i);
            ans3 += f(l, (a + i) * (b - i) / __gcd(a + i, b - i));
        }
        ans2 = cnt1 + cnt2 - 2 * ans3;
        ans1 = l * (a + b + 1) - ans2 - ans3;
        printf("%lld\n%lld\n%lld\n", ans1, ans2 - 2, ans3 + 2);
        return 0;
    }
}

int main() { return SLV::main(); }

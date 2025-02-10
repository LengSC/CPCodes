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

    constexpr int MOD = 1e9 + 7;

    struct Mat {
        ll a[3][3];

        Mat() { memset(a, 0, sizeof(a)); }

        Mat operator*(const Mat &b) const {
            Mat res; int r;
            rep(i, 1, 2) rep(k, 1, 2) {
                r = a[i][k];
                rep(j, 1, 2) (res.a[i][j] += b.a[k][j] * r) %= MOD;
            }
            return res;
        }
    } ans, bas;

    ll n;

    int main() {
        read(n);
        if (n <= 2) return puts("1"), 0;
        bas.a[1][1] = bas.a[1][2] = bas.a[2][1] = 1;
        ans.a[1][1] = ans.a[1][2] = 1;
        n -= 2;
        for (; n; n >>= 1, bas = bas * bas) if (n & 1) ans = ans * bas;
        printf("%lld\n", ans.a[1][1]);
        return 0;
    }
}

int main() { return SLV::main(); }

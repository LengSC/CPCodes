#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    using vi = vector<int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 3.5e4 + 5, INF = 0x3f3f3f3f;

    int n, a[N], f[N], minn[N], len;
    vi r[N];
    ll g[N], pre[N], suf[N];

    int main() {
        read(n); rep(i, 1, n) read(a[i]), a[i] -= i;
        a[0] = -INF, a[n + 1] = INF;
        rep(i, 1, n + 1) {
            f[i] = upper_bound(minn + 1, minn + 1 + len, a[i]) - minn;
            len = max(len, f[i]);
            minn[f[i]] = a[i];
            r[f[i]].eb(i);
        }
        memset(g, 63, sizeof(g));
        g[0] = 0; r[0].eb(0);
        rep(i, 1, n + 1)
            for (const auto &l: r[f[i] - 1]) {
                if (l > i || a[l] > a[i]) continue;
                pre[l - 1] = suf[i] = 0;
                dep(k, l, i)
                    pre[k] = pre[k - 1] + abs(a[k] - a[l]);
                per(k, i - 1, l)
                    suf[k] = suf[k + 1] + abs(a[k + 1] - a[i]);
                dep(k, l, i)
                    g[i] = min(g[i], g[l] + pre[k] + suf[k]);
            }
        printf("%d\n%lld\n", n - len + 1, g[n + 1]);
        return 0;
    }
}

int main() { return SLV::main(); }

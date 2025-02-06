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

    constexpr int N = 2e7 + 5;

    uint t, n, k, x, ans;
    uint f[N], g[N];
    bitset<N> np;
    vi pr;

    uint fpow(uint a, uint b) {
        uint res = 1;
        for (; b; b >>= 1, a *= a) if (b & 1) res *= a;
        return res;
    }

    void pre(uint lim) {
        f[1] = g[1] = 1;
        rep(i, 2, lim) {
            if (!np[i]) pr.eb(i), f[i] = i - 1, g[i] = fpow(i, k);
            for (const auto &j: pr) {
                if (i * j > lim) break;
                np[i * j] = true;
                g[i * j] = g[i] * g[j];
                if (i % j) f[i * j] = f[i] * f[j];
                else {
                    uint q = i / j;
                    if (q % j) f[i * j] = -j * f[q];
                    break;
                }
            }
        }
        rep(i, 2, lim) f[i] = f[i - 1] + f[i] * g[i], g[i] += g[i - 1];
        rep(i, 2, lim) g[i] += g[i - 1];
    }

    int main() {
        read(t, n, k);
        pre(n * 2);
        rep(i, 1, t) {
            read(x);
            ans = 0;
            for (int l = 1, r; l <= x; l = r + 1)
                r = x / (x / l),
                ans += (f[r] - f[l - 1]) * (g[x / l * 2] - g[x / l] * 2);
            printf("%u\n", ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

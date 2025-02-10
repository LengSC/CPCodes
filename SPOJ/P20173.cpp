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

    constexpr int N = 1e8, M = 1e6, Q = 1e4;

    int t, mu[M + 2];
    bitset<N + 2> np;
    vi pr;
    unordered_map<ull, ull> mp;
    ull q[Q + 2], lim, d[N + 2], p;

    void pre() {
        d[1] = mu[1] = 1;
        rep(i, 2, lim) {
            if (!np[i]) {
                pr.eb(i);
                if (i <= M) mu[i] = -1;
                d[i] = 2;
            }
            for (const auto &j: pr) {
                if ((p = i * j) > lim) break;
                np[p] = true;
                if (i % j) {
                    if (p <= M) mu[p] = -mu[i];
                    d[p] = d[i] * d[j];
                } else {
                    d[p] = d[i] * d[j] - d[i / j];
                    break;
                }
            }
        }
        rep(i, 2, lim) d[i] += d[i - 1];
    }

    ull sSigma(ull n) {
        if (n <= N) return d[n];
        if (mp[n]) return mp[n];
        ull res = 0, l, r, x;
        for (l = 1; l <= n; l = r + 1)
            r = n / (x = n / l),
            res += (r - l + 1) * x;
        return mp[n] = res;
    }

    ull g(ull n) {
        ull res = 0, l, r, x;
        for (l = 1; l <= n; l = r + 1)
            r = n / (x = n / l),
            res += (sSigma(r) - sSigma(l - 1)) * x;
        return res;
    }

    void solve(ull n) {
        ull ans = 0;
        rep(i, 1, sqrt(n)) ans += g(n / i / i) * mu[i];
        printf("%llu\n", ans);
    }

    int main() {
        read(t);
        rep(i, 1, t) read(q[i]), lim = max(lim, q[i]);
        lim = min(lim, (ull)N);
        pre();
        rep(i, 1, t) solve(q[i]);
        return 0;
    }
}

int main() { return SLV::main(); }

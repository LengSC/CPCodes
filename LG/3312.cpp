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

    constexpr int N = 1e5, Q = 2e4;

    int t, c[N + 2], mu[N + 2], g[N + 2], p, ans[N + 2];
    pii sigma[N + 2];
    bitset<N + 2> np;
    vi pr;

    void add(int x, int val) { for (; x <= N; x += x & -x) c[x] += val; }

    int qry(int x) { int res = 0; for (; x; x ^= x & -x) res += c[x]; return res; }

    struct Query {
        int n, m, a, id;
        friend bool operator<(const Query &lhs, const Query &rhs) { return lhs.a < rhs.a; }
        int solve() {
            if (n > m) swap(n, m);
            int res = 0, l, r, x, y;
            for (l = 1; l <= n; l = r + 1)
                r = min(n / (x = n / l), m / (y = m / l)),
                res += (qry(r) - qry(l - 1)) * x * y;
            return res;
        }
    } q[Q + 2];

    void pre() {
        mu[1] = 1, sigma[1] = {1, 1};
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), mu[i] = -1, g[i] = i + 1, sigma[i] = {i + 1, i};
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) mu[p] = -mu[i], g[p] = j + 1, sigma[p] = {sigma[i].fi * sigma[j].fi, p};
                else { g[p] = g[i] * j + 1, sigma[p] = {sigma[i].fi / g[i] * g[p], p}; break; }
            }
        }
        sort(sigma + 1, sigma + 1 + N);
    }

    int main() {
        pre();
        read(t); rep(i, 1, t) read(q[i].n, q[i].m, q[i].a), q[i].id = i;
        sort(q + 1, q + 1 + t);
        for (int i = 1, j = 1; i <= t; ++i) {
            while (sigma[j].fi <= q[i].a && j <= N) {
                for (int k = sigma[j].se; k <= N; k += sigma[j].se) add(k, sigma[j].fi * mu[k / sigma[j].se]);
                ++j;
            }
            ans[q[i].id] = q[i].solve();
        }
        rep(i, 1, t) printf("%d\n", ans[i] & 2147483647);
        return 0;
    }
}

int main() { return SLV::main(); }

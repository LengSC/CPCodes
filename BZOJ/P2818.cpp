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

    constexpr int N = 1e7;

    int n, mu[N + 2], f[N + 2], p;
    bitset<N + 2> np;
    vi pr;
    ll ans;

    void pre() {
        mu[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), mu[i] = -1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) mu[p] = -mu[i];
                else break;
            }
        }
        for (const auto &i: pr)
            for (int j = 1; i * j <= N; ++j) f[i * j] += mu[j];
        rep(i, 2, N) f[i] += f[i - 1];
    }

    int main() {
        pre();
        read(n);
        for (int l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            ans += (ll)(f[r] - f[l - 1]) * x * x;
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

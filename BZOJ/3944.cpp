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

    constexpr int N = 2e6;

    ll t, n, p, mu[N + 2];
    bitset<N + 2> np;
    vi pr;
    map<ll, ll> mpMu;

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
        rep(i, 2, N) mu[i] += mu[i - 1];
    }

    ll sMu(ll n) {
        if (n <= N) return mu[n];
        if (mpMu[n]) return mpMu[n];
        ll res = 1;
        for (ll l = 2, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            res -= sMu(x) * (r - l + 1);
        return mpMu[n] = res;
    }

    ll sPhi(ll n) {
        if (n == 0) return 0;
        ll res = 0;
        for (ll l = 1, r, x; l <= n; l = r + 1)
            r = n / (x = n / l),
            res += (sMu(r) - sMu(l - 1)) * x * x;
        return (res - 1) / 2 + 1;
    }

    int main() {
        for (pre(), read(t); t; --t) read(n), printf("%lld %lld\n", sPhi(n), sMu(n));
        return 0;
    }
}

int main() { return SLV::main(); }

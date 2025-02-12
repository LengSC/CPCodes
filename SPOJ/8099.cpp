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

    constexpr int N = 1e7, MOD = 20101009;

    ll n, m, mu[N + 2], p;
    vi pr;
    bitset<N + 2> np;

    void pre(ll lim) {
        mu[1] = 1;
        rep(i, 2, lim) {
            if (!np[i]) pr.eb(i), mu[i] = -1;
            for (const auto &j: pr) {
                if ((p = i * j) > lim) break;
                np[p] = true;
                if (i % j) mu[p] = -mu[i];
                else { mu[p] = 0; break; }
            }
        }
        rep(i, 2, lim) mu[i] = (mu[i - 1] + mu[i] * i % MOD * i) % MOD;
    }

    ll s(ll n, ll m) {
        return (n * (n + 1) / 2 % MOD) * (m * (m + 1) / 2 % MOD) % MOD;
    }

    ll f(ll n, ll m) {
        ll res = 0, l, r, x, y;
        if (n > m) swap(n, m);
        for (l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            (res += (mu[r] - mu[l - 1]) * s(x, y)) %= MOD;
        return res;
    }

    ll g(ll n, ll m) {
        ll res = 0, l, r, x, y;
        if (n > m) swap(n, m);
        for (l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            (res += (l + r) * (r - l + 1) / 2 % MOD * f(x, y)) %= MOD;
        return res;
    }

    int main() {
        read(n, m);
        pre(max(n, m));
        printf("%lld\n", (g(n, m) + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

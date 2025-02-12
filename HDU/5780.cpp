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

    constexpr int N = 1000000, MOD = 1e9 + 7;

    ll t, n, x, phi[N + 2], p, l, r, k, ans;
    bitset<N + 2> np;
    vi pr;

    void pre() {
        phi[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), phi[i] = i - 1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) phi[p] = phi[i] * phi[j];
                else { phi[p] = phi[i] * j; break; }
            }
        }
        rep(i, 2, N) (phi[i] += phi[i - 1]) %= MOD;
    }

    ll fpow(ll a, ll b = MOD - 2) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll f(ll a, ll b) {
        return ((fpow(x, b + 1) - fpow(x, a)) * fpow(x - 1) - (b - a + 1)) % MOD;
    }

    void solve() {
        read(x, n);
        if (x == 1) return puts("0"), void();
        for (ans = 0, l = 1; l <= n; l = r + 1)
            r = n / (k = n / l),
            (ans += (2 * phi[k] - 1) * f(l, r)) %= MOD;
        printf("%lld\n",(ans + MOD) % MOD);
    }

    int main() {
        pre();
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

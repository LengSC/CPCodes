#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 1e7 + 5, M = 665000;

    ll T, n, phi[N], ans, factor[N];
    vector<ll> pr;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a *= a) if (b & 1) res *= a;
        return res;
    }

    void pre() {
        phi[1] = 1;
        dep(i, 2, N) {
            if (!factor[i]) pr.eb(i), phi[i] = i - 1, factor[i] = i;
            for (const auto &j: pr) {
                if (i * j >= N) break;
                factor[i * j] = j;
                if (j < factor[i]) phi[i * j] = phi[i] * phi[j];
                else { phi[i * j] = phi[i] * j; break; }
            }
        }
        dep(i, 2, N) phi[i] += phi[i - 1];
    }

    void solve() {
        read(n);
        ans = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans += phi[n / l] * (phi[r] - phi[l - 1]);
        }
        printf("%lld\n", ans * 2 - phi[n]);
    }

    int main() {
        for (read(T), pre(); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

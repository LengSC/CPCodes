#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    using pll = pair<ll, ll>;
    namespace IO {
        template<typename T>
        void read(T &x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    constexpr int N = 64, MOD = 1e9 + 7;

    ll n, m, k, tu, tv, powk[N], fa[N], ans;
    vector<ll> g[N], tg[N];
    map<pll, ll> mp;

    ll find(ll x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool dfs(ll u, ll to, ll fr, ll id) {
        if (u == to) return true;
        for (const auto &v: g[u]) {
            if (v == fr) continue;
            if (dfs(v, to, u, id)) return tg[id].eb(mp[pll(u, v)]), true;
        }
        return false;
    }

    ll calc(ll id) {
        rep(i, 1, n - 1) fa[i] = i;
        rep(i, 1, m) if (id & (1ull << (i - 1))) for (const auto &u: tg[i]) fa[find(u)] = find(tg[i][0]);
        ll res = 0;
        rep(i, 1, n - 1) res += (fa[i] == i);
        return res;
    }

    int main() {
        read(n, m, k);
        powk[0] = 1;
        rep(i, 1, n) powk[i] = powk[i - 1] * k % MOD;
        rep(i, 1, n - 1) read(tu, tv), g[tu].eb(tv), g[tv].eb(tu), mp[pll(tu, tv)] = mp[pll(tv, tu)] = i;
        rep(i, 1, m) read(tu, tv), dfs(tu, tv, tu, i);
        for (ll i = 0; i < (1ull << m); ++i) ans = (ans + ((__builtin_popcount(i) & 1) ? -1 : 1) * powk[calc(i)]) % MOD;
        printf("%lld\n", (ans + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

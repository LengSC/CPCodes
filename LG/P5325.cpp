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

    constexpr int N = 5e6, MOD = 1e9 + 7, INV2 = 500000004, INV6 = 166666668;;

    ll n, ans, p, phi[N + 2], pr[N + 2], cnt;
    bitset<N + 2> np;
    unordered_map<ll, ll> mp;

    void pre() {
        phi[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr[++cnt] = i, phi[i] = i - 1;
            for (int j = 1; j <= cnt && (p = i * pr[j]) <= N; ++j) {
                np[p] = true;
                if (i % pr[j]) phi[p] = phi[i] * (pr[j] - 1) % MOD;
                else { phi[p] = phi[i] * pr[j] % MOD; break; }
            }
        }
        rep(i, 2, N) phi[i] = (phi[i - 1] + phi[i] * i) % MOD;
    }

    ll sf(ll n) {
        if (n <= N) return phi[n];
        if (mp[n]) return mp[n];
        ll res = (n % MOD) * ((n + 1) % MOD) % MOD * ((2 * n + 1) % MOD) % MOD * INV6 % MOD, l, r, x;
        for (l = 2; l <= n; l = r + 1)
            r = n / (x = n / l),
            (res -= ((l + r) % MOD) * ((r - l + 1) % MOD) % MOD * INV2 % MOD * sf(x)) %= MOD;
        return mp[n] = res;
    }

    void dfs(ll k, ll m, ll h) {
        if (k > cnt || m * pr[k] > n) {
            ll x = n / m;
            if (x <= N) (ans += phi[x] * h) %= MOD;
            else (ans += mp[x] * h) %= MOD;
            return;
        }
        ll tmp = pr[k] * pr[k];
        dfs(k + 1, m, h);
        for (int e = 2; m * tmp <= n; tmp *= pr[k], ++e)
            dfs(k + 1, m * tmp, tmp % MOD * (pr[k] - 1) % MOD * (e - 1) % MOD * h % MOD);
    }

    int main() {
        read(n);
        pre(), sf(n), dfs(1, 1, 1);
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

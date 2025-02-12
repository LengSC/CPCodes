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
 
    constexpr int N = 7e6 + 5, MOD = 998244353, INV6 = 166374059;
 
    int t, n, m, tot, l, r;
    ll f[N], ans, pr[N], p, x, y;
    bitset<N> np;
 
    void pre() {
        f[1] = 1;
        dep(i, 2, N) {
            if (!np[i]) pr[++tot] = i, f[i] = i - 1;
            for (int j = 1; j <= tot; ++j) {
                if ((p = pr[j] * i) >= N) break;
                np[p] = true;
                if (i % pr[j]) f[p] = f[i] * f[pr[j]] % MOD;
                else {
                    ll q = i / pr[j];
                    if (q % pr[j]) f[p] = -pr[j] * f[q] % MOD;
                    break;
                }
            }
        }
        dep(i, 2, N) f[i] = (f[i - 1] + f[i] * i % MOD * i) % MOD;
    }
 
    void solve() {
        read(n, m);
        if (n > m) swap(n, m);
        ans = 0;
        for (l = 1, r; l <= n; l = r + 1) {
            x = n / l, y = m / l;
            r = min(n / x, m / y);
            (ans += (f[r] - f[l - 1]) * ((((x + 1) * (x * 2 + 1) % MOD + (y + 1) * (y * 2 + 1) % MOD) * x % MOD * y % MOD * INV6 + x * (x + 1) / 2 % MOD * y % MOD * (y + 1)) % MOD) % MOD) %= MOD;
        }
        printf("%lld\n", (ans + MOD) % MOD);
    }
 
    int main() {
        for (read(t), pre(); t; --t) solve();
        return 0;
    }
}
 
int main() { return SLV::main(); }

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

constexpr int N = 505, M = 125255, Q = 10005, MOD = 1e9 + 7;

int T, maxn, f[M], s[M], n[Q], e[Q], ans[Q], fac[N], inv[N], lim;

int fpow(int a, int b = MOD - 2) {
    ll res = 1;
    for (; b; b >>= 1, a = (ll)a * a % MOD) if (b & 1) res = (ll)res * a % MOD;
    return res;
}

int comb(int n, int m) { return (ll)fac[n] * inv[n - m] % MOD * inv[m] % MOD; }

int main() {
    read(T);
    rep(i, 1, T) read(n[i], e[i]), maxn = max(maxn, n[i]);
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = (ll)fac[i - 1] * i % MOD;
    inv[maxn] = fpow(fac[maxn]);
    per(i, maxn, 1) inv[i - 1] = (ll)inv[i] * i % MOD;
    s[0] = 1;
    rep(i, 1, maxn) {
        lim = i * (i - 1) / 2;
        rep(j, 0, lim) f[j] = (s[j] - (j >= i ? s[j - i] : 0)) % MOD;
        lim = i * (i + 1) / 2;
        rep(j, 1, lim) s[j] = (s[j - 1] + f[j]) % MOD;
        rep(j, 1, T) if (n[j] >= i)
            ans[j] = (ans[j] + (ll)s[min(e[j], lim)] * (n[j] - i + 1) % MOD * comb(n[j], i) % MOD * comb(n[j], i) % MOD * fac[n[j] - i] % MOD * fac[n[j] - i]) % MOD;
    }
    rep(i, 1, T) printf("%d\n", (ans[i] + MOD) % MOD);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

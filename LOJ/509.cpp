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

constexpr ll N = 122474500;

ll n, m, ans;
int sumu2[N], p, lim;
short mu[N];
vi pr;
bitset<N> np;
unordered_map<ll, ll> mp;

void pre() {
    // sumu2[n] = $\sum \limits_{i=1}^{n}{\mu^2(i)}$
    mu[1] = sumu2[1] = 1;
    rep(i, 2, lim) {
        if (!np[i]) pr.eb(i), mu[i] = -1;
        for (int j: pr) {
            if ((p = i * j) > lim) break;
            np[p] = true;
            if (i % j) mu[p] = -mu[i];
            else break;
        }
        sumu2[i] = sumu2[i - 1] + mu[i] * mu[i];
        mu[i] += mu[i - 1];
    }
}

ll sMu2(ll n) {
    if (n <= lim) return sumu2[n];
    if (mp[n]) return mp[n];
    ll res = 0, i = 1, _i = cbrt(n), _l = sqrt(n);
    for (; i <= _i; ++i)
        res += (mu[i] - mu[i - 1]) * (n / (i * i));
    for (ll l = i, r, x; l <= _l; l = r + 1)
        r = sqrt(n / (x = n / (l * l))),
        res += (mu[r] - mu[l - 1]) * x;
    return mp[n] = res;
}

int main() {
    read(n, m);
    if (n > m) swap(n, m);
    lim = sqrt(n);
    pre();
    for (ll l = 1, r, x, y; l <= n; l = r + 1)
        x = sqrt(n / l), y = sqrt(m / l),
        r = min(n / (x * x), m / (y * y)),
        ans += (sMu2(r) - sMu2(l - 1)) * x * y;
    printf("%lld\n", ans);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }
/*
Ans = \sum \limits_{x=1}^{\min(N, M)}{\mu^2(x) \cdot \lfloor \sqrt{\lfloor N / x \rfloor} \rfloor \cdot \lfloor \sqrt{\lfloor M / x \rfloor} \rfloor} \\
S\mu^2(n) = \sum \limits_{i=1}^{\sqrt{n}}{\mu(i)} \cdot \lfloor \frac{n}{i^2} \rfloor
*/

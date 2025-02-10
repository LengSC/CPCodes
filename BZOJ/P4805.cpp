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

    constexpr int N = 1600000;

    ll n, phi[N], p;
    bitset<N + 2> np;
    vi pr;
    unordered_map<ll, ll> mp;

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
        rep(i, 2, N) phi[i] += phi[i - 1];
    }

    ll sPhi(ll n) {
        if (n <= N) return phi[n];
        if (mp[n]) return mp[n];
        ll res = n * (n + 1) / 2, l, r, x;
        for (l = 2; l <= n; l = r + 1)
            r = n / (x = n / l),
            res -= (r - l + 1) * sPhi(x);
        return mp[n] = res;
    }

    int main() {
        pre();
        read(n);
        printf("%lld\n", sPhi(n));
        return 0;
    }
}

int main() { return SLV::main(); }

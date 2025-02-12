#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 1e8 + 1;

    ll T, n, tn, ans, cnt, tmp, mul;
    bitset<N> np;
    vector<ll> pr;

    void pre() {
        dep(i, 2, N) {
            if (!np[i]) pr.eb(i);
            for (const auto &j: pr) {
                if (i * j >= N) break;
                np[i * j] = true;
                if (i % j == 0) break;
            }
        }
    }

    void solve() {
        read(n);
        ans = 1, tn = n;
        for (const auto &i: pr) {
            if (i * i > n) break;
            cnt = 0;
            while (n % i == 0) ++cnt, n /= i;
            tmp = mul = 1;
            rep(j, 1, cnt) mul *= i, tmp += mul;
            ans *= tmp;
        }
        if (n ^ 1) ans *= (n + 1);
        printf("%lld\n", ans - tn);
    }

    int main() {
        pre();
        for (read(T); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

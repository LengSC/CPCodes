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

    constexpr int N = 1e6 + 2, MOD = 1e9 + 7;

    int t, n, pi[N], num[N], j;
    char s[N];
    ll ans;

    void solve() {
        scanf("%s", s + 1);
        ans = num[1] = 1, j = 0;
        rep(i, 2, n = strlen(s + 1)) {
            while (j && s[i] != s[j + 1]) j = pi[j];
            if (s[i] == s[j + 1]) ++j;
            pi[i] = j, num[i] = num[j] + 1;
        }
        j = 0;
        rep(i, 2, n) {
            while (j && s[i] != s[j + 1]) j = pi[j];
            if (s[i] == s[j + 1]) ++j;
            while ((j * 2) > i) j = pi[j];
            (ans *= (num[j] + 1)) %= MOD;
        }
        printf("%lld\n", ans);
    }

    int main() {
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

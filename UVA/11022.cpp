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

    constexpr int N = 82, INF = 0x3f3f3f3f;

    int pi[N], f[N][N];
    char s[N];

    int dp(int l, int r) {
        if (f[l][r]) return f[l][r];
        if (l == r) return f[l][r] = 1;
        f[l][r] = INF;
        dep(i, l, r) f[l][r] = min(f[l][r], dp(l, i) + dp(i + 1, r));
        memset(pi, 0, sizeof(pi));
        int j = 0;
        rep(i, l + 1, r) {
            while (j && s[i] != s[j + l]) j = pi[j];
            if (s[i] == s[j + l]) ++j;
            pi[i] = j;
        }
        int len = r - l + 1, per = len - pi[r];
        if (len % per == 0)
            f[l][r] = min(f[l][r], dp(l, l + per - 1));
        return f[l][r];
    }

    int main() {
        while (scanf("%s", s + 1), s[1] != '*') {
            memset(f, 0, sizeof(f));
            printf("%d\n", dp(1, strlen(s + 1)));
        }
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 3e6 + 2;

    int ch[N][26], cnt[N], tot, n, dp[N], ans;
    char s[N];

    void rinsert(const char *s) {
        int u = 0, c;
        per(i, strlen(s) - 1, 0) {
            c = s[i] - 'a';
            if (!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
        ++cnt[u];
    }

    void dfs(int u) {
        int v, siz = 0, mx1 = 0, mx2 = 0;
        dep(c, 0, 26) if (v = ch[u][c]) {
            dfs(v);
            siz += cnt[v];
            if (mx1 < dp[v]) mx2 = mx1, mx1 = dp[v];
            else if (mx2 < dp[v]) mx2 = dp[v];
        }
        if (cnt[u]) dp[u] = mx1 + max(siz, 1);
        ans = max(ans, mx1 + mx2 + cnt[u] + max(siz - 2, 0));
    }

    int main() {
        read(n);
        rep(i, 1, n) scanf("%s", s), rinsert(s);
        dfs(0);
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

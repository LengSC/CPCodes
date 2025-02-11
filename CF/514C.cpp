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

    constexpr int N = 6e5 + 2;

    int n, m, ch[N][3], tot, tag[N], len;
    char s[N];

    void insert(const char *s) {
        int u = 0, c;
        dep(i, 0, strlen(s)) {
            c = s[i] - 'a';
            if (!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
        tag[u] = 1;
    }

    bool dfs(int i, int u, int st) {
        if (i == len) return st && tag[u];
        int c = s[i] - 'a';
        if (ch[u][c] && dfs(i + 1, ch[u][c], st)) return true;
        if (st) return false;
        rep(j, 0, 2) if (c != j && ch[u][j] && dfs(i + 1, ch[u][j], 1)) return true;
        return false;
    }

    int main() {
        read(n, m);
        rep(i, 1, n) scanf("%s", s), insert(s);
        rep(i, 1, m) scanf("%s", s), len = strlen(s), puts(dfs(0, 0, 0) ? "YES" : "NO");
        return 0;
    }
}

int main() { return SLV::main(); }

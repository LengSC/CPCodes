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

    constexpr int N = 2e6 + 2;

    int n, ans, tot, f[N], id[N];
    char s[N];
    unordered_map<int, unordered_map<int, int>> ch;

    int main() {
        read(n);
        rep(i, 1, n) {
            scanf("%s", s);
            int u = 0, c, l = strlen(s);
            dep(j, 0, l) {
                f[i] = max(f[i], f[id[u]] + 1);
                c = (s[j] - 'A') * 26 + s[l - j - 1] - 'A';
                if (ch[u].find(c) == ch[u].end()) ch[u][c] = ++tot;
                u = ch[u][c];
            }
            if (id[u]) f[i] = max(f[i], f[id[u]] + 1);
            ans = max(ans, f[i]);
            id[u] = i;
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

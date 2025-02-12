#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    using ll = long long;
    using vi = vector<int>;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    int n, deg[26];
    vi g[26], ans;
    string s[102];
    bitset<26> vis;
    queue<int> q;

    void work(const string &a, const string &b) {
        int len = min(a.size(), b.size());
        dep(i, 0, len)
            if (a[i] == b[i]) continue;
            else return ++deg[b[i] - 'a'], g[a[i] - 'a'].eb(b[i] - 'a');
    }

    int main() {
        read(n);
        rep(i, 1, n) {
            cin >> s[i];
            for (const auto &j: s[i]) vis[j - 'a'] = true;
        }
        dep(i, 1, n) rep(j, i + 1, n) work(s[i], s[j]);
        dep(i, 0, 26) if (vis[i] && !deg[i]) q.emplace(i);
        while (!q.empty()) {
            if (q.size() > 1) puts("?"), exit(0);
            int u = q.front(); q.pop();
            ans.eb(u);
            for (const auto &v: g[u]) if (!(--deg[v])) q.emplace(v);
        }
        dep(i, 0, 26) if (vis[i] && deg[i]) puts("!"), exit(0);
        for (const auto &i: ans) putchar(i + 'a');
        puts("");
        return 0;
    }
}

int main() { return SLV::main(); }

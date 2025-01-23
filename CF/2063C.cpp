#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    namespace IO {
        template<typename T>
        void read(T &x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    constexpr int N = 2e5 + 2;

    vector<int> g[N];
    multiset<int> s;
    int t, n, deg[N], tu, tv, ans;

    void solve() {
        read(n);
        rep(i, 2, n) {
            read(tu, tv);
            g[tu].eb(tv);
            g[tv].eb(tu);
            ++deg[tu];
            ++deg[tv];
        }

        rep(u, 1, n) {
            int maxn = 0;
            for (const auto &v: g[u]) maxn = max(maxn, deg[v]);
            ans = max(ans, deg[u] + maxn - 2);
        }

        rep(u, 1, n) s.emplace(deg[u]);

        rep(u, 1, n) {
            s.erase(s.find(deg[u]));
            for (const auto &v: g[u]) s.erase(s.find(deg[v]));
            if (!s.empty()) ans = max(ans, deg[u] + *s.rbegin() - 1);
            s.emplace(deg[u]);
            for (const auto &v: g[u]) s.emplace(deg[v]);
        }

        printf("%d\n", ans);

        ans = 0;
        memset(deg, 0, sizeof(deg));
        rep(i, 1, n) g[i].clear();
        s.clear();
    }

    int main() {
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

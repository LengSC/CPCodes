#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
    #define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)
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

    constexpr int N = 110, MOD = 1e9 + 7;

    int n, m, ans, fa[N], siz[N], d[N][N], e[N], c[N][N], cnt[N], tx[N], ty[N], in[N];
    vector<int> g[N];
    char ch;
    bool root[N], eq[N];

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        cerr << "mer: " << x << " " << y << endl;
        return (x == y ? true : (fa[x] = y, false));
    }

    void dfs(int u, int fa) {
        siz[u] = d[u][1] = 1;
        for (const auto &v: g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            rep(i, 1, n) e[i] = 0;
            rep(i, 1, siz[u] + siz[v]) rep(j, 1, siz[u]) rep(k, 1, siz[v]) {
                int x = k - i + j;
                if (x < 0) continue;
                (e[i] += (ll)d[u][j] * d[v][k] % MOD * c[i - 1][j - 1] % MOD * c[j - 1][x] % MOD) %= MOD;
            }
            rep(i, 1, siz[u] + siz[v]) d[u][i] = e[i];
            siz[u] += siz[v];
        }
    }

    int main() {
        read(n, m);
        rep(i, 0, n + 2) c[i][0] = 1;
        rep(i, 1, n + 2) rep(j, 1, i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        rep(i, 1, n) fa[i] = i;
        rep(i, 1, m) {
            read(tx[i]), scanf("%c", &ch), read(ty[i]);
            if (eq[i] = (ch == '=')) merge(tx[i], ty[i]);   
        }
        rep(i, 1, n) root[in[i] = find(i)] = true;
        rep(i, 1, n) fa[i] = i;
        rep(i, 1, m)
            if (!eq[i]) {
                if (merge(in[tx[i]], in[ty[i]])) return puts("0"), 0;
                g[in[tx[i]]].emplace_back(in[ty[i]]);
                g[in[ty[i]]].emplace_back(in[tx[i]]);
                ++cnt[in[ty[i]]];
            }
        rep(i, 1, n)
            if (root[i] && !cnt[i]) {
                g[n + 1].emplace_back(i);
                g[i].emplace_back(n + 1);
                break;
            }
        dfs(n + 1, 0);
        rep(i, 1, siz[n + 1]) (ans += d[n + 1][i]) %= MOD;
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
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

    int n, q, op, x, y, k;
    vector<int> g[N];

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            int ans, sum, add, tag;
        } tr[N << 2];

        void down(int cur, int l, int r) {
            if (tr[cur].add) {
                tr[ls].add += tr[cur].add;
                tr[rs].add += tr[cur].add;
                tr[ls].sum += tr[cur].add * (mid - l + 1);
                tr[rs].sum += tr[cur].add * (r - mid);
                tr[cur].add = 0;
            }
            if (tr[cur].tag != -1) {
                tr[ls].tag = tr[rs].tag = tr[cur].tag;
                tr[ls].ans = tr[ls].sum * tr[cur].tag;
                tr[rs].ans = tr[rs].sum * tr[cur].tag;
                tr[cur].tag = -1;
            }
        }

        void uAdd(int cur, int l, int r, int ql, int qr, int x) {
            if (ql <= l && r <= qr) return tr[cur].sum += x * (r - l + 1), tr[cur].add += x, void();
            if (qr < l || ql > r) return;
            down(cur, l, r);
            uAdd(ls, l, mid, ql, qr, x), uAdd(rs, mid + 1, r, ql, qr, x);
            tr[cur].sum = tr[ls].sum + tr[rs].sum;
        }

        void qry(int cur, int l, int r, int ql, int qr, int x) {
            if (ql <= l && r <= qr) return tr[cur].ans = tr[cur].sum * x, tr[cur].tag = x, void();
            if (qr < l || ql > r) return;
            down(cur, l, r);
            qry(ls, l, mid, ql, qr, x), qry(rs, mid + 1, r, ql, qr, x);
            tr[cur].ans = tr[ls].ans + tr[rs].ans;
        }
        #undef ls
        #undef rs
        #undef mid
    }

    namespace HLD {
        #define tu top[u]
        #define tv top[v]
        int fa[N], dep[N], siz[N], son[N], top[N], dfn[N], cnt;

        void dfs1(int u, int f) {
            fa[u] = f, siz[u] = 1, dep[u] = dep[f] + 1;
            for (const auto &v: g[u]) {
                if (v == f) continue;
                dfs1(v, u);
                siz[u] += siz[v];
                if (siz[v] > siz[son[u]]) son[u] = v;
            }
        }

        void dfs2(int u, int f) {
            top[u] = f, dfn[u] = ++cnt;
            if (son[u]) dfs2(son[u], f);
            for (const auto &v: g[u]) {
                if (v == fa[u] || v == son[u]) continue;
                dfs2(v, v);
            }
        }

        void uAdd(int u, int v, int x) {
            while (tu != tv) {
                if (dep[tu] > dep[tv]) swap(u, v);
                SGT::uAdd(1, 1, n, dfn[tv], dfn[v], x);
                v = fa[tv];
            }
            if (dep[u] > dep[v]) swap(u, v);
            SGT::uAdd(1, 1, n, dfn[u], dfn[v], x);
        }

        void qry(int u, int v) {
            while (tu != tv) {
                if (dep[tu] > dep[tv]) swap(u, v);
                SGT::qry(1, 1, n, dfn[tv], dfn[v], 1);
                v = fa[tv];
            }
            if (dep[u] > dep[v]) swap(u, v);
            SGT::qry(1, 1, n, dfn[u], dfn[v], 1);
        }
        #undef tu
        #undef tv
    }

    int main() {
        read(n);
        rep(i, 2, n) read(x, y), g[x].emplace_back(y), g[y].emplace_back(x);
        HLD::dfs1(1, 0);
        HLD::dfs2(1, 1);
        for (read(q); q; --q) {
            read(op);
            if (op == 0) { // modify
                read(x, y);
                SGT::uAdd(1, 1, n, HLD::dfn[x], HLD::dfn[x] + HLD::siz[x] - 1, y);
            } else {  // query
                for (read(k); k; --k) {
                    read(x, y);
                    HLD::qry(x, y);
                }
                printf("%d\n", SGT::tr[1].ans & 0x7fffffff);
                SGT::qry(1, 1, n, 1, n, 0);
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }

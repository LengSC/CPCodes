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

    constexpr int N = 50, INF = 0x3f3f3f3f;

    struct Bit {
        int c[N], siz;
        void init(int s) { memset(c, 0, sizeof(c)), siz = s; }
        void add(int x, int val) { for (; x <= siz; x += x & -x) c[x] += val; }
        int qry(int x) { int res = 0; for (; x; x ^= x & -x) res += c[x]; return res; }
        int qry(int l, int r) { return qry(r) - qry(l - 1); }
    } u, d;

    int t, n, a[N], l[N], r[N], ans, cnt, tmp;

    void dfs(int cur, int sum = 0) {
        if (sum >= ans) return;
        if (cur > cnt) return ans = min(ans, sum), void();
        tmp = min(u.qry(l[cur], r[cur]), d.qry(l[cur], n) + u.qry(r[cur], n));
        u.add(r[cur], 1); dfs(cur + 1, sum + tmp); u.add(r[cur], -1);
        tmp = min(d.qry(l[cur], r[cur]), u.qry(l[cur], n) + d.qry(r[cur], n));
        d.add(r[cur], 1); dfs(cur + 1, sum + tmp); d.add(r[cur], -1);
    }

    void solve() {
        ans = INF, cnt = 0;
        read(n); rep(i, 1, n) read(a[i]);
        dep(i, 1, n) rep(j, i + 1, n) if (a[i] == a[j]) { l[++cnt] = i, r[cnt] = j; break; }
        u.init(n), d.init(n);
        dfs(1);
        printf("%d\n", ans);
    }
    int main() {
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

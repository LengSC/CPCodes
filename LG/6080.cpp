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

    constexpr int N = 1e5 + 2, M = 2.5e4 + 2;

    int la, lb, uselessvar, pi[N], a[N], b[M], l[M], r[M], j;
    set<pii> q;
    set<pii>::iterator it;
    vi ans;

    bool check(const int *s, int x, int y) {
        if (l[y]) {
            if (b[l[y]] == b[y] && s[x - (y - l[y])] != s[x]) return false;
            else if (b[l[y]] < b[y] && s[x - (y - l[y])] >= s[x]) return false;
        }
        if (r[y]) {
            if (b[r[y]] == b[y] && s[x + (r[y] - y)] != s[x]) return false;
            else if (b[r[y]] > b[y] && s[x + (r[y] - y)] <= s[x]) return false;
        }
        return true;
    }

    int main() {
        read(la, lb, uselessvar);
        rep(i, 1, la) read(a[i]);
        rep(i, 1, lb) {
            read(b[i]);
            q.emplace(b[i], -i);
            it = ++q.lower_bound({b[i], -i});
            j = -it->se;
            if (b[j] >= b[i]) r[i] = j;
            j = -(----it)->se;
            if (b[j] <= b[i]) l[i] = j;
        }
        j = 0;
        rep(i, 2, lb) {
            while (j && !check(b, i, j + 1)) j = pi[j];
            if (check(b, i, j + 1)) ++j;
            pi[i] = j;
        }
        j = 0;
        rep(i, 1, la) {
            while (j && !check(a, i, j + 1)) j = pi[j];
            if (check(a, i, j + 1)) ++j;
            if (j == lb) ans.eb(i - lb + 1), j = pi[j];
        }
        printf("%d\n", ans.size());
        for (const auto &i: ans) printf("%d\n", i);
        return 0;
    }
}

int main() { return SLV::main(); }

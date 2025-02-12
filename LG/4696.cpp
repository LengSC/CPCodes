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

    constexpr int N = 1e6 + 2;

    int la, lb, j, a[N], b[N], p[N], pi[N], pre[N], nxt[N], l[N], r[N], ans[N], cnt;

    bool check(const int *s, int i, int j, int pre, int nxt) {
        return (pre ? (s[i - (j - pre)] < s[i]) : true) & (nxt ? (s[i + (nxt - j)] > s[i]) : true);
    }

    int main() {
        read(lb, la);
        rep(i, 1, lb) read(p[i]);
        rep(i, 1, lb) b[p[i]] = i;
        rep(i, 1, la) read(a[i]);
        rep(i, 1, lb) l[i] = p[b[i] - 1], r[i] = p[b[i] + 1];
        per(i, la, 1) pre[i] = l[r[i]] = l[i], nxt[i] = r[l[i]] = r[i];
        rep(i, 2, lb) {
            while (j && !check(b, i, j + 1, pre[j + 1], nxt[j + 1])) j = pi[j];
            if (check(b, i, j + 1, pre[j + 1], nxt[j + 1])) ++j;
            pi[i] = j;
        }
        j = 0;
        rep(i, 1, la) {
            while (j && !check(a, i, j + 1, pre[j + 1], nxt[j + 1])) j = pi[j];
            if (check(a, i, j + 1, pre[j + 1], nxt[j + 1])) ++j;
            if (j == lb) ans[++cnt] = i - lb + 1, j = pi[j];
        }
        printf("%d\n", cnt);
        rep(i, 1, cnt) printf("%d ", ans[i]);
        return 0;
    }
}

int main() { return SLV::main(); }

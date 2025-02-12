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

    constexpr int N = 2e5 + 2;

    int pi[N], la, lb, a[N], b[N], j, ans;

    int main() {
        read(la, lb);
        if (lb == 1) return printf("%d\n", la), 0;
        dep(i, 0, la) read(a[i]);
        per(i, la, 1) a[i] -= a[i - 1];
        --la;
        dep(i, 0, lb) read(b[i]);
        per(i, lb, 1) b[i] -= b[i - 1];
        --lb;
        rep(i, 2, lb) {
            while (j && b[i] != b[j + 1]) j = pi[j];
            if (b[i] == b[j + 1]) ++j;
            pi[i] = j;
        }
        j = 0;
        rep(i, 1, la) {
            while (j && a[i] != b[j + 1]) j = pi[j];
            if (a[i] == b[j + 1]) ++j;
            if (j == lb) ++ans, j = pi[j];
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

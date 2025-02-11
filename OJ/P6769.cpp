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

    int n, m, ch[N][26], tag[N], tot;
    char s[N];

    void insert(const char *s) {
        int u = 0, c;
        dep(i, 0, strlen(s)) {
            c = s[i] - 'a';
            if (!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
        ++tag[u];
    }

    int countPref(const char *s) {
        int u = 0, c, res = 0;
        dep(i, 0, strlen(s)) {
            c = s[i] - 'a';
            if (!ch[u][c]) break;
            u = ch[u][c];
            res += tag[u];
        }
        return res;
    }

    int main() {
        read(n, m);
        rep(i, 1, n) scanf("%s", s), insert(s);
        rep(i, 1, m) scanf("%s", s), printf("%d\n", countPref(s));
        return 0;
    }
}

int main() { return SLV::main(); }

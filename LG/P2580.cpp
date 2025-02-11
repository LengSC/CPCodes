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

    constexpr int N = 5e5 + 2;

    char s[N];
    int n, m, ch[N][26], tag[N], tot;

    void insert(const char *s, int l) {
        int u = 0, c;
        dep(i, 0, l) {
            c = s[i] - 'a';
            if (!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
        tag[u] = 1;
    }

    void find(const char *s, int l) {
        int u = 0, c;
        dep(i, 0, l) {
            c = s[i] - 'a';
            if (!ch[u][c]) break;
            u = ch[u][c];
        }
        if (tag[u] == 1) puts("OK"), tag[u] = 2;
        else if (tag[u] == 2) puts("REPEAT");
        else puts("WRONG");
    }

    int main() {
        read(n); rep(i, 1, n) {
            scanf("%s", s);
            insert(s, strlen(s));
        }
        read(m); rep(i, 1, m) {
            scanf("%s", s);
            find(s, strlen(s));
        }
        return 0;
    }
}

int main() { return SLV::main(); }

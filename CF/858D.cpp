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

    constexpr int N = 4e6, M = 7e4 + 2;

    int n, ch[N][10], tag[N], tot, minn;
    char s[M][10], tmp[10], ans[10];

    void insert(const char *s) {
        int u = 0, c;
        dep(i, 0, strlen(s)) {
            c = s[i] - '0';
            if (!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
            ++tag[u];
        }
    }

    void erase(const char *s) {
        int u = 0, c;
        dep(i, 0, strlen(s)) {
            c = s[i] - '0';
            u = ch[u][c];
            --tag[u];
        }
    }

    void qry(const char *s) {
        int u = 0, c;
        dep(i, 0, strlen(s)) {
            tmp[i] = s[i];
            c = s[i] - '0';
            u = ch[u][c];
            if (!tag[u]) {
                if (i + 1 < minn) {
                    minn = i + 1;
                    tmp[i + 1] = '\0';
                    strcpy(ans, tmp);
                    break;
                }
            }
        }
    }

    int main() {
        read(n);
        rep(i, 1, n) {
            scanf("%s", s[i]);
            dep(j, 0, 9) insert(s[i] + j);
        }
        rep(i, 1, n) {
            minn = 10;
            dep(j, 0, 9) erase(s[i] + j);
            dep(j, 0, 9) qry(s[i] + j);
            dep(j, 0, 9) insert(s[i] + j);
            puts(ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using ll = long long;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 102;

    int m, n, a[N][N], s[N][N], ans, sum;

    void add(int x1, int y1, int x2, int y2, int val) { s[x1][y1] += val, s[x2 + 1][y2 + 1] += val, s[x1][y2 + 1] -= val, s[x2 + 1][y1] -= val; }

    void calc(const int &r, const int &c) {
        __builtin_memset(s, 0, sizeof(s));
        rep(i, 1, n) rep(j, 1, m) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (s[i][j] > a[i][j]) return;
            if (s[i][j] < a[i][j]) {
                if (i + r - 1 > n || j + c - 1 > m) return;
                add(i, j, i + r - 1, j + c - 1, a[i][j] - s[i][j]);
            }
        }
        ans = max(ans, r * c);
    }

    int main() {
        read(n, m);
        rep(i, 1, n) rep(j, 1, m) read(a[i][j]), sum += a[i][j];
        rep(r, 1, n) rep(c, 1, m) {
            if (sum % (r * c) || r * c <= ans) continue;
            calc(r, c);
        }
        printf("%d\n", sum / ans);
        return 0;
    }
}

int main() { return SLV::main(); }

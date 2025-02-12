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

    constexpr int N = 1002;

    int T, q, n, c[N][N], x1, y1, x2, y2;
    char op[5];

    void add(int x, int y) {
        for (; x <= n; x += x & -x)
            for (int i = y; i <= n; i += i & -i)
                ++c[x][i];
    }

    int query(int x, int y) {
        int res = 0;
        for (; x; x ^= x & -x)
            for (int i = y; i; i ^= i & -i)
                res += c[x][i];
        return res;
    }

    int main() {
        for (read(T); T; --T) {
            memset(c, 0, sizeof(c));
            for (read(n, q); q; --q) {
                scanf("%s", op);
                if (op[0] == 'Q') {
                    read(x1, y1);
                    printf("%d\n", query(x1, y1) % 2);
                } else {
                    read(x1, y1, x2, y2);
                    add(x2 + 1, y2 + 1);
                    add(x1, y2 + 1);
                    add(x2 + 1, y1);
                    add(x1, y1);
                }
            }
            puts("");
        }
        return 0;
    }
}

int main() { return SLV::main(); }
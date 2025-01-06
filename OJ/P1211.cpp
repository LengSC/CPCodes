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

    constexpr int N = 1030;

    int c[N][N], op, s, x, y, a, l, b, r, t;

    void add(int x, int y, int v) {
        for (; x <= s; x += x & -x)
            for (int i = y; i <= s; i += i & -i)
                c[x][i] += v;
    }

    int query(int x, int y) {
        int res = 0;
        for (; x; x ^= x & -x)
            for (int i = y; i; i ^= i & -i)
                res += c[x][i];
        return res;
    }

    int main() {
        for (;;) {
            read(op);
            switch (op) {
            case 0:
                read(s);
                break;
            case 1:
                read(x, y, a);
                add(x + 1, y + 1, a);
                break;
            case 2:
                read(l, b, r, t);
                printf("%d\n", query(r + 1, t + 1) - query(l, t + 1) - query(r + 1, b) + query(l, b));
                break;
            case 3:
                return 0;
                break;
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }
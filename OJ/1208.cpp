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

    struct {
        int x1, y1, x2, y2, clr;
    } rec[1001];

    int a, b, n, reg[1001];

    void dfs(int x1, int y1, int x2, int y2, int clr, int dpt) {
        while (dpt <= n && (x1 >= rec[dpt].x2 || y1 >= rec[dpt].y2 || x2 <= rec[dpt].x1 || y2 <= rec[dpt].y1)) ++dpt;
        if (dpt > n)
            return reg[clr] += (x2 - x1) * (y2 - y1), void();
        if (x1 < rec[dpt].x1) dfs(x1, y1, rec[dpt].x1, y2, clr, dpt + 1), x1 = rec[dpt].x1;
        if (y1 < rec[dpt].y1) dfs(x1, y1, x2, rec[dpt].y1, clr, dpt + 1), y1 = rec[dpt].y1;
        if (x2 > rec[dpt].x2) dfs(rec[dpt].x2, y1, x2, y2, clr, dpt + 1), x2 = rec[dpt].x2;
        if (y2 > rec[dpt].y2) dfs(x1, rec[dpt].y2, x2, y2, clr, dpt + 1), y2 = rec[dpt].y2;
    }

    int main() {
        read(a, b, n);
        rep(i, 1, n)
            read(rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2, rec[i].clr);
        dfs(0, 0, a, b, 1, 1);
        rep(i, 1, n)
            dfs(rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2, rec[i].clr, i + 1);
        rep(i, 1, 1000)
            if (reg[i]) printf("%d %d\n", i, reg[i]);
        return 0;
    }
}

int main() { return SLV::main(); }
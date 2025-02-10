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

    int t, k, a, b, c;
    double f[50][8][8][8];

    void pre() {
        rep(k, 1, 49) rep(a, 0, 7) rep(b, 0, 7 - a) rep(c, 0, 7 - a - b) {
            int tot = a + b + c + 1;
            if (a) f[k][a][b][c] += a * f[k - 1][a - 1][b][c] / tot;
            if (b) f[k][a][b][c] += b * f[k - 1][a + 1][b - 1][c + (tot < 8)] / tot;
            if (c) f[k][a][b][c] += c * f[k - 1][a][b + 1][c - 1 + (tot < 8)] / tot;
            f[k][a][b][c] += (f[k - 1][a][b][c] + 1) / tot;
        }
    }

    int main() {
        for (pre(), read(t); t; --t) read(k, a, b, c), printf("%.2lf\n", f[k][a][b][c]);
        return 0;
    }
}

int main() { return SLV::main(); }

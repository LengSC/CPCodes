#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
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

    struct ScanLine {
        int xa, ya, xb, yb, z, v;
    } q[205];

    int n, ans, x, y, z, r, area;
    int f[2005][2005];

    int main() {
        read(n);
        rep(i, 1, n) {
            read(x, y, z, r);
            x += 1000, y += 1000, z += 1000;
            q[(i << 1) - 1] = {x - r + 1, y - r + 1, x + r, y + r, z - r, 1};
            q[i << 1] = {x - r + 1, y - r + 1, x + r, y + r, z + r, -1};
        }
        n <<= 1;
        sort(q + 1, q + 1 + n, [](const ScanLine &a, const ScanLine &b) {
            return a.z < b.z;
        });
        dep(i, 1, n) {
            rep(j, q[i].xa, q[i].xb)
                rep(k, q[i].ya, q[i].yb) {
                    f[j][k] += q[i].v;
                    if (q[i].v == 1 && f[j][k] == 1) ++area;
                    else if (q[i].v == -1 && f[j][k] == 0) --area;
                }
            ans += area * (q[i + 1].z - q[i].z);
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

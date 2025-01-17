#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
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

    constexpr int N = 1e5 + 2;

    ll c, n, a, sum[N], vis[N], cnt;

    bool solve() {
        read(c, n);
        if (c == 0 && n == 0) return false;
        memset(vis, 0, sizeof(vis));
        rep(i, 1, n) read(a), sum[i] = sum[i - 1] + a;
        rep(i, 1, n) {
            if (sum[i] % c == 0) {
                rep(j, 1, i) printf("%d%c", j, " \n"[j == i]);
                return true;
            } else if (vis[sum[i] % c]) {
                rep(j, vis[sum[i] % c] + 1, i) printf("%d%c", j, " \n"[j == i]);
                return true;
            }
            vis[sum[i] % c] = i;
        }
        return puts("no sweets"), true;
    }

    int main() {
        while (solve());
        return 0;
    }
}

int main() { return SLV::main(); }

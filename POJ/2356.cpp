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

    int n, a[N], sum[N], vis[N];

    int main() {
        read(n);
        rep(i, 1, n) {
            read(a[i]);
            sum[i] = sum[i - 1] + a[i];
            if (sum[i] % n == 0) {
                printf("%d\n", i);
                rep(j, 1, i) printf("%d\n", a[j]);
                break;
            } else if (vis[sum[i] % n]) {
                printf("%d\n", i - vis[sum[i] % n]);
                rep(j, vis[sum[i] % n] + 1, i) printf("%d\n", a[j]);
                break;
            }
            vis[sum[i] % n] = i;
        }
        return 0;
    }
}

int main() { return SLV::main(); }

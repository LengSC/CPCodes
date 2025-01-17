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

    constexpr int N = 2e5 + 2;

    int n, m, a[N], ans = 1;

    int main() {
        read(n, m);
        if (n > m) return puts("0"), 0;
        rep(i, 1, n) read(a[i]);
        rep(i, 1, n) rep(j, i + 1, n)
            ans = (ll)ans * abs(a[i] - a[j]) % m;
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

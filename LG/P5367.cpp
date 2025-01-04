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

    constexpr int N = 1e6 + 2, MOD = 998244353;

    int n, a[N], b[N], c[N], ans = 1, fac = 1;

    int query(int x) {
        int res = 0;
        for (; x; x ^= x & -x) (res += c[x]) %= MOD;
        return res;
    }

    void add(int x) {
        for (; x <= n; x += x & -x) (++c[x]) %= MOD;
    }

    int main() {
        read(n);
        rep(i, 1, n) read(a[i]);
        per(i, n, 1) {
            b[i] = query(a[i] - 1);
            add(a[i]);
        }
        per(i, n, 1) {
            ans = (ans + (ll)b[i] * fac) % MOD;
            fac = (ll)fac * (n - i + 1) % MOD;
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }
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

    constexpr int N = 5e5 + 5;

    int n, len, a[N], b[N];
    ll ans;

    namespace BIT {
        int c[N];

        void init() {
            memset(c, 0, sizeof(c));
        }

        void add(int x, int v) {
            for (; x <= n; x += x & -x) c[x] += v;
        }

        int qry(int x) {
            int res = 0;
            for (; x; x -= x & -x) res += c[x];
            return res;
        }
    }

    void solve() {
        ans = 0;
        BIT::init();
        rep(i, 1, n) read(a[i]);
        memcpy(b, a, sizeof(a));
        sort(b + 1, b + 1 + n);
        len = unique(b + 1, b + 1 + n) - b - 1;
        rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        per(i, n, 1) {
            ans += BIT::qry(a[i] - 1);
            BIT::add(a[i], 1);
        }
        printf("%lld\n", ans);
    }

    int main() {
        while(read(n), n != 0) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

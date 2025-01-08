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

    constexpr int MOD = 1000;

    int k, x, ans[1145];

    int fpow(int a, int b) {
        int res = 1;
        for (; b; a = a * a % MOD, b >>= 1) if (b & 1) res = res * a % MOD;
        return res;
    }

    void C(int a, int b) {
        ans[0] = ans[1] = 1;
        rep(i, 1, b) {
            rep(j, 1, ans[0]) ans[j] *= (a - i + 1);
            rep(j, 1, ans[0]) ans[j + 1] += ans[j] / 10000, ans[j] %= 10000;
            while (ans[ans[0] + 1]) ++ans[0];
            int tmp = 0;
            per(j, ans[0], 1) tmp = tmp * 10000 + ans[j], ans[j] = tmp / i, tmp %= i;
            while (!ans[ans[0]]) --ans[0];
        }
    }

    int main() {
        read(k, x); x %= MOD; x = fpow(x, x);
        // ans <- C(x - 1, k - 1);
        cerr << x << " " << k << endl;
        C(x - 1, k - 1);
        printf("%d", ans[ans[0]]);
        per(i, ans[0] - 1, 1) printf("%04d", ans[i]);
        puts("");
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 2e5 + 5, MOD = 998244353;

    ll n, k, a[2][N], len, f[N][2], now;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll calc(ll a[]) {
        ll res = 1, &len = a[0];
        dep(i, 1, len) if (a[i] != -1 && a[i] == a[i + 1]) return 0;
        for (int st = 1, ed; st <= len; st = ed + 1) {
            while (st <= len && a[st] != -1) ++st; ed = st;
            while (ed <= len && a[ed] == -1) ++ed; --ed;
            if (st > ed) continue;
            if (st == 1 && ed == len) return k * fpow(k - 1, len - 1) % MOD;
            if (st == 1 || ed == len) (res *= (f[ed - st][1] + f[ed - st][0] * (k - 1) % MOD)) %= MOD;
            else (res *= f[ed - st + 1][a[st - 1] == a[ed + 1]]) %= MOD;
        }
        return res;
    }

    int main() {
        read(n, k); rep(i, 1, n) read(a[now][++a[now][0]]), now ^= 1;
        f[0][0] = 1, f[0][1] = 0;
        rep(i, 1, n)
            f[i][1] = f[i - 1][0] * (k - 1) % MOD,
            f[i][0] = (f[i - 1][1] + f[i - 1][0] * (k - 2)) % MOD;
        printf("%lld\n", calc(a[0]) * calc(a[1]) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

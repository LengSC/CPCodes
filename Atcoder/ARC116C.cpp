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

    constexpr int N = 2e5 + 50, MOD = 998244353;

    ll n, m, fac[N], inv[N], ans;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll C(ll a, ll b) {
        // if (b == 0 || a == b) return 1;
        return fac[a] * inv[a - b] % MOD * inv[b] % MOD;
    }

    int main() {
        read(n, m);
        // n: length, m: maximum
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % MOD;
        inv[N - 1] = fpow(fac[N - 1], MOD - 2);
        per(i, N - 2, 0) inv[i] = inv[i + 1] * (i + 1) % MOD;
        rep(i, 1, m) {
            ll tmp = i, sum = 1, cnt;
            rep(j, 2, sqrt(i)) {
                cnt = 0;
                while (tmp % j == 0) ++cnt, tmp /= j;
                sum = sum * C(n + cnt - 1, n - 1) % MOD;
            }
            if (tmp > 1) sum = sum * n % MOD;
            ans = (ans + sum) % MOD;
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

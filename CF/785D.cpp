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

    constexpr int N = 2e5 + 5, MOD = 1e9 + 7;

    ll n, ans, fac[N], inv[N], l[N], r[N];
    char s[N];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (res *= a) %= MOD;
        return res;
    }

    ll c(ll a, ll b) {
        return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    int main() {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        fac[0] = 1;
        rep(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = fpow(fac[n], MOD - 2);
        per(i, n - 1, 0) inv[i] = inv[i + 1] * (i + 1) % MOD;
        rep(i, 1, n) l[i] = l[i - 1] + (s[i] == '(');
        per(i, n, 1) r[i] = r[i + 1] + (s[i] == ')');
        rep(i, 1, n)
            if (s[i] == '(')
                (ans += c(l[i] + r[i] - 1, l[i])) %= MOD;
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

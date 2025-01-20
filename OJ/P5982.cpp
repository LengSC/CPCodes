#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define fi first
    #define se second
    using namespace std;
    using ll = long long;
    using pll = pair<ll, ll>;
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

    constexpr int N = 502, M = 1e6 + 2, MOD = 1e9 + 7;

    ll ex, ey, n, ax, ay, bx, by, fac[M], inv[M], cban = 1, tx, ty, f[N];
    pll ban[N];

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll comb(ll a, ll b) {
        return (b > a ? 0 : fac[a] * inv[a - b] % MOD * inv[b] % MOD);
    }

    pll calc(ll x, ll y) {
        ll resa = -1, resb = -1, t1 = ax * by - ay * bx, t2 = x * by - y * bx;
        if (t2 % t1 == 0) resa = t2 / t1;
        t1 = ay * bx - ax * by, t2 = x * ay - y * ax;
        if (t2 % t1 == 0) resb = t2 / t1;
        return pll(resa, resb);
    }

    int main() {
        fac[0] = 1;
        rep(i, 1, M - 1) fac[i] = fac[i - 1] * i % MOD;
        inv[M - 1] = fpow(fac[M - 1], MOD - 2);
        per(i, M - 1, 1) inv[i - 1] = inv[i] * i % MOD;
        read(ex, ey, n, ax, ay, bx, by);
        ban[1] = calc(ex, ey);
        if (ban[1].fi < 0 || ban[1].se < 0) return puts("0"), 0;
        rep(i, 1, n) {
            read(tx, ty);
            ban[0] = calc(tx, ty);
            if (ban[0].fi >= 0 && ban[0].se >= 0 && ban[0].fi <= ban[1].fi && ban[0].se <= ban[1].se) ban[++cban] = ban[0];
        }
        sort(ban + 1, ban + 1 + cban);
        n = unique(ban + 1, ban + 1 + cban) - ban - 1;
        rep(i, 1, n) {
            f[i] = comb(ban[i].fi + ban[i].se, ban[i].fi);
            rep(j, 1, i - 1)
                f[i] = (f[i] - f[j] * comb(ban[i].fi + ban[i].se - ban[j].fi - ban[j].se, ban[i].fi - ban[j].fi) % MOD) % MOD;
        }
        printf("%lld\n", (f[n] + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

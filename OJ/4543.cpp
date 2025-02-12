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
        void read(T& x) {
            x = 0; char c = getchar(); bool f = false;
            while (!isdigit(c)) f = (c == '-'), c = getchar();
            while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
            if (f) x = -x;
        }
        template<typename T, typename ...Nxt>
        void read(T& x, Nxt &...nxt) { read(x), read(nxt...); }
    } using namespace IO;

    constexpr int N = 202, M = 1e6 + 5;

    ll t, mod, f[N], p[5] = { 1000003, 3, 5, 6793, 10007 }, fac[5][M], inv[5][M], m[5], invm[5];
    pll ban[N];
    bool flg;

    ll fpow(ll a, ll b, ll p) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % p) if (b & 1) res = res * a % p;
        return res;
    }

    ll lucas(ll a, ll b, ll i) {
        if (a < b) return 0;
        if (!b) return 1;
        if (a < p[i] && b < p[i]) return fac[i][a] * inv[i][b] % p[i] * inv[i][a - b] % p[i];
        return lucas(a % p[i], b % p[i], i) * lucas(a / p[i], b / p[i], i) % p[i];
    }

    ll comb(ll a, ll b) {
        if (flg) {
            ll res = 0;
            rep(i, 1, 4) res = (res + lucas(a, b, i) * m[i] % mod * invm[i] % mod) % mod;
            return res;
        } else return lucas(a, b, 0);
    }

    int main() {
        read(ban[1].fi, ban[1].se, t, mod); ++t;
        rep(i, 2, t) read(ban[i].fi, ban[i].se);
        sort(ban + 1, ban + 1 + t);

        if (mod == 1000003) {
            fac[0][0] = 1;
            rep(i, 1, mod - 1) fac[0][i] = fac[0][i - 1] * i % mod;
            inv[0][mod - 1] = fpow(fac[0][mod - 1], mod - 2, mod);
            per(i, mod - 1, 1) inv[0][i - 1] = inv[0][i] * i % mod;
        } else {
            flg = true;
            rep(i, 1, 4) {
                m[i] = mod / p[i];
                invm[i] = fpow(m[i], p[i] - 2, p[i]);
                fac[i][0] = 1;
                rep(j, 1, p[i] - 1) fac[i][j] = fac[i][j - 1] * j % p[i];
                inv[i][p[i] - 1] = fpow(fac[i][p[i] - 1], p[i] - 2, p[i]);
                per(j, p[i] - 1, 1) inv[i][j - 1] = inv[i][j] * j % p[i];
            }
        }

        rep(i, 1, t) {
            f[i] = comb(ban[i].fi + ban[i].se, ban[i].fi);
            rep(j, 1, i - 1)
                if (ban[j].fi <= ban[i].fi && ban[j].se <= ban[i].se)
                    f[i] = (f[i] - f[j] * comb(ban[i].fi + ban[i].se - ban[j].fi - ban[j].se, ban[i].fi - ban[j].fi) % mod + mod) % mod;
        }
        printf("%lld\n", f[t]);
        return 0;
    }
}

int main() { return SLV::main(); }

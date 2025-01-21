#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define fi first
    #define se second
    using namespace std;
    using ll = long long;
    using pii = pair<int, int>;
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

    constexpr int N = 2005, M = 2e5 + 5, MOD = 1e9 + 7;

    int n, fac[M], inv[M], f[N];
    pii ban[N];
    
    int fpow(int a, int b) {
        int res = 1;
        for (; b; b >>= 1, a = (ll)a * a % MOD) if (b & 1) res = (ll)res * a % MOD;
        return res;
    }

    int comb(int a, int b) {
        return a < b ? 0 : (ll)fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    }

    int main() {
        fac[0] = 1;
        rep(i, 1, M - 1) fac[i] = (ll)fac[i - 1] * i % MOD;
        inv[M - 1] = fpow(fac[M - 1], MOD - 2);
        per(i, M - 1, 1) inv[i - 1] = (ll)inv[i] * i % MOD;
        read(ban[1].fi, ban[1].se, n);
        --ban[1].fi, --ban[1].se, ++n;
        rep(i, 2, n) read(ban[i].fi, ban[i].se), --ban[i].fi, --ban[i].se;
        sort(ban + 1, ban + 1 + n);
        rep(i, 1, n) {
            f[i] = comb(ban[i].fi + ban[i].se, ban[i].fi);
            rep(j, 1, i - 1) f[i] = (f[i] - (ll)f[j] * comb(ban[i].fi + ban[i].se - ban[j].fi - ban[j].se, ban[i].fi - ban[j].fi) % MOD) % MOD;
        }
        printf("%d\n", (f[n] + MOD) % MOD);
        return 0;
    }
}

int main() { return SLV::main(); }

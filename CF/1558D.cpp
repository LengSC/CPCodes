#include <bits/stdc++.h>
#include <bits/extc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    using namespace __gnu_pbds;
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

    constexpr int N = 2e5 + 2, MOD = 998244353;

    int t, n, m, x[N], y[N], cnt;
    ll frc[N * 2], inv[N * 2];
    bool vis[N];
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
    vector<int> tx;

    ll fpow(ll a, ll b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
        return res;
    }

    ll C(ll n, ll m) {
        return (n < m) ? 0 : (frc[n] * inv[n - m] % MOD * inv[m] % MOD);
    }

    void pre() {
        frc[0] = 1;
        rep(i, 1, N * 2 - 1) frc[i] = frc[i - 1] * i % MOD, s.insert(i);
        inv[N * 2 - 1] = fpow(frc[N * 2 - 1], MOD - 2);
        per(i, N * 2 - 1, 1) inv[i - 1] = inv[i] * i % MOD;
    }

    void init() {
        for (const auto &i: tx) s.insert(i);
        memset(vis, false, sizeof(vis));
        tx.clear();
        cnt = 0;
    }

    void solve() {
        read(n, m);
        rep(i, 1, m) read(x[i], y[i]);
        per(i, m, 1) {
            auto posx = s.find_by_order(y[i] - 1), posy = s.find_by_order(y[i]);
            cnt += !vis[*posy];
            vis[*posy] = true;
            tx.emplace_back(*posx);
            s.erase(posx);
        }
        printf("%lld\n", C(n * 2 - cnt - 1, n));
        init();
    }

    int main() {
        pre();
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

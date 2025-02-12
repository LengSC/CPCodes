#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    using uint = unsigned int;
    using ll = long long;
    using ull = unsigned long long;
    using vi = vector<int>;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 5000, M = 1e6, S = 1000, MOD = 998244353;

    int n, a[N + 2], b[N + 2];
    ll ans, mul;
    int fac[M + 2][3], g[S + 2][S + 2], p;
    bitset<M + 2> np;
    vi pr;

    void pre() {
        fac[1][0] = fac[1][1] = fac[1][2] = 1;
        rep(i, 2, M) {
            if (!np[i]) pr.eb(i), fac[i][0] = fac[i][1] = 1, fac[i][2] = i;
            for (const int &j: pr) {
                if ((p = i * j) > M) break;
                np[p] = true;
                fac[p][0] = fac[i][0] * j, fac[p][1] = fac[i][1], fac[p][2] = fac[i][2];
                if (fac[p][0] > fac[p][1]) {
                    swap(fac[p][0], fac[p][1]);
                    if (fac[p][1] > fac[p][2])
                        swap(fac[p][1], fac[p][2]);
                }
                if (i % j == 0) break;
            }
        }
        rep(i, 0, S) g[0][i] = g[i][0] = i;
        rep(i, 1, S) rep(j, 1, i) g[i][j] = g[j][i] = g[j][i % j];
    }

    int gcd(int a, int b) {
        int res = 1, tmp;
        dep(i, 0, 3) {
            tmp = (fac[a][i] > S)
                ? (b % fac[a][i] ? 1 : fac[a][i])
                : g[fac[a][i]][b % fac[a][i]];
            b /= tmp;
            res *= tmp;
        }
        return res;
    }

    int main() {
        pre();
        read(n);
        rep(i, 1, n) read(a[i]);
        rep(i, 1, n) read(b[i]);
        rep(i, 1, n) {
            ans = 0, mul = i;
            rep(j, 1, n)
                (ans += mul * gcd(a[i], b[j])) %= MOD, (mul *= i) %= MOD;
            printf("%lld\n", ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

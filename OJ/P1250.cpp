#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    using namespace std;
    using ll = long long;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 1e5 + 5, M = 1e6 + 5, INF = 0x3f3f3f3f;

    int n, a[N], maxa = -INF, omega[M], minp1[M], minp2[M], ans, dis, pr[N], tot;
    bitset<M> np;

    void pre(int x) {
        rep(i, 2, x) {
            if (!np[i]) pr[++tot] = i, omega[i] = 1;
            for (int j = 1; j <= tot && i * pr[j] <= x; ++j) {
                np[i * pr[j]] = true;
                omega[i * pr[j]] = omega[i] + 1;
                if (i % pr[j] == 0) break;
            }
        }
    }

    void upd(int val, int pos) {
        if (omega[a[pos]] < omega[a[minp1[val]]])
            minp2[val] = minp1[val], minp1[val] = pos;
        else if (omega[a[pos]] < omega[a[minp2[val]]] && pos != minp1[val])
            minp2[val] = pos;
    }

    void qry(int val, int pos) {
        int tp = minp1[val] == pos ? minp2[val] : minp1[val],
           td = omega[a[pos]] + omega[a[tp]] - 2 * omega[val];
        if (td < dis || (td == dis && tp < ans))
            dis = td, ans = tp;
    }

    int main() {
        read(n); rep(i, 1, n) read(a[i]), maxa = max(maxa, a[i]);
        pre(maxa); omega[0] = INF;
        rep(i, 1, n) rep(j, 1, sqrt(a[i])) {
            if (a[i] % j) continue;
            upd(j, i);
            upd(a[i] / j, i);
        }
        rep(i, 1, n) {
            dis = INF;
            rep(j, 1, sqrt(a[i])) {
                if (a[i] % j) continue;
                qry(j, i);
                qry(a[i] / j, i);
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

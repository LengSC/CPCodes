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

constexpr int N = 1e6 + 2;

int n, mod, q;
int fa[N], g[N];
ll d[N];
int op, u, v, w, e, f, fu, fv, x, y;

int find(int x) {
    if (x == fa[x]) return x;
    int t = find(fa[x]);
    (d[x] += d[fa[x]]) %= mod;
    return fa[x] = t;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void exgcd(int a, int b, int &x, int &y) {
    if (!b) x = 1, y = 0;
    else exgcd(b, a % b, y, x), y -= a / b * x;
}

int main() {
    read(n, mod, q);
    rep(i, 1, n) fa[i] = i, g[i] = mod;
    rep(i, 1, q) {
        read(op, u, v, w);
        fu = find(u), fv = find(v);
        if (op == 1) {
            if (fu == fv) g[fu] = gcd(g[fu], gcd((d[u] + d[v] + w) % mod, 2 * w));
            else fa[fu] = fv, d[fu] = (d[u] + d[v] + w) % mod, g[fv] = gcd(gcd(g[fu], g[fv]), 2 * w);
        } else {
            read(e, f); // w + ke, 0 <= k < f
            int a = e % g[fu], b = g[fu], c = (d[u] + d[v] - w + b) % b, t = gcd(a, b);
            if (fu != fv || c % t) {
                puts("0");
                continue;
            }
            a /= t, b /= t, c /= t;
            exgcd(a, b, x, y);
            x = ((ll)x * c % b + b) % b;
            printf("%d\n", x < f ? (f - 1 - x) / b + 1 : 0);
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

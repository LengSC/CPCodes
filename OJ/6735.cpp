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

constexpr int N = 2e6 + 2;

int n, op, x, la, now, tot, top[N], pre[N], ver[N];

int main() {
    read(n);
    rep(i, 1, n) {
        read(op, x); op = (op + la - 1) % 4 + 1;
        switch (op) {
        case 1:
            x ^= la;
            top[++tot] = x, pre[tot] = now;
            ver[i] = now = tot;
            break;
        case 2:
            if (now) printf("%d\n", la = top[now]);
            else la = 0;
            ver[i] = now = pre[now];
            break;
        case 3:
            (x += la) %= i;
            ver[i] = now = ver[x];
            break;
        case 4:
            if (now) printf("%d\n", la = top[now]);
            else la = 0;
            ver[i] = now;
            break;
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

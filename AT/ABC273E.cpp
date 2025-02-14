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

constexpr int N = 5e5 + 2;

int t, pre[N], top[N], tot, now, x;
char op[7];
unordered_map<int, int> ver;

int main() {
    for (read(t); t; --t) {
        scanf("%s", op);
        if (op[0] != 'D') read(x);
        switch (op[0]) {
        case 'A': top[++tot] = x, pre[tot] = now, now = tot; break;
        case 'D': now = pre[now]; break;
        case 'S': ver[x] = now; break;
        case 'L': now = ver[x]; break;
        }
        printf("%d ", top[now] ? top[now] : -1);
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

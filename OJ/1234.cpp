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

constexpr int N = 2e4 + 2;

int x, y;
char op[10];

namespace BIT {
    int c[N];

    void add(int x, int val) { for (; x <= N; x += x & -x) c[x] ^= val; }

    int qry(int x) {
        int res = 0;
        for (; x; x ^= x & -x) res ^= c[x];
        return res;
    }

    int qry(int l, int r) { return qry(r) ^ qry(l - 1); }
}

int main() {
    while (~scanf("%s", op)) {
        switch (op[0]) {
        case 'A': read(x); BIT::add(x, x); break;
        case 'R': read(x); BIT::add(x, x); break;
        case 'X': read(x, y); printf("%d\n", (x > y) ? 0 : BIT::qry(x, y)); break;
        default: assert(false);
        }
    }
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

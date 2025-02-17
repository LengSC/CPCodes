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

constexpr int N = 1e5 + 5, INF = 0x3f3f3f3f;

int a[N], b[N], la, lb;
char s[N];

void maintain(int *a, int x) {
    a[x - 1] += ((a[x] - (a[x] & 1)) >> 1);
    a[x] &= 1;
}

void phase(const char *s, int *a, int &len) {
    rep(i, 1, strlen(s + 1)) switch(s[i]) {
        case '1': a[++len] = 0; break;
        case '2': a[++len] = 1; break;
        case 'U': maintain(a, len), --len; break;
        case 'L': --a[len]; break;
        case 'R': ++a[len]; break;
    }
    per(i, len, 2) maintain(a, i);
}

int ans = INF;

int main() {
    scanf("%s", s + 1); phase(s, a, la);
    scanf("%s", s + 1); phase(s, b, lb);
    for (int i = 0, l = min(la, lb), dis = 0; i <= l && abs(dis) < INF; ++i)
        dis = dis * 2 + (a[i] - b[i]),
        ans = min(ans, abs(dis) + (l - i) * 2);
    printf("%d\n", ans + abs(la - lb));
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

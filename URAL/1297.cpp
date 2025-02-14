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

constexpr int N = 2e5 + 2;

int n, p[N * 2], cnt, maxp, maxl;
char a[N], s[N * 2];

int main() {
    scanf("%s", a + 1);
    s[0] = '$', s[cnt = 1] = '|';
    rep(i, 1, n = strlen(a + 1)) s[++cnt] = a[i], s[++cnt] = '|'; 
    for (int i = 2, mid = 0, maxr = 0; i <= cnt; ++i) {
        p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
        while (s[i - p[i]] == s[i + p[i]]) ++p[i];
        if (i + p[i] > maxr) mid = i, maxr = i + p[i];
        if (p[i] > maxl) maxl = p[i], maxp = i;
    }
    --maxl;
    rep(i, (maxp - maxl) / 2 + 1, (maxp + maxl) / 2) putchar(a[i]);
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

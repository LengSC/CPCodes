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

constexpr int N = 12, S = 1.5e4 + 2, BASE = 998244353, INF = 0x3f3f3f3f;

int t, n, len[N], l, r, mid, ans;
char s[S];
ull hash[N][S], b[S];
unordered_map<ull, int> lst, cnt[N];
vector<ull> vc;

bool check(int x) {
    vc.clear();
    rep(i, 1, n) {
        lst.clear(), cnt[i].clear();
        rep(j, 1, len[i] - x + 1) {
            ull h = hash[i][j + x - 1] - hash[i][j - 1] * b[x];
            vc.eb(h);
            if (lst[h] < j) ++cnt[i][h], lst[h] = j + x - 1;
        }
    }
    for (const auto &i: vc) {
        bool flg = true;
        rep(j, 1, n)  if (cnt[j][i] < 2) { flg = false; break; }
        if (flg) return true;
    }
    return false;
}

void solve() {
    read(n);
    l = 1, r = INF, ans = 0;
    rep(i, 1, n) {
        scanf("%s", s + 1);
        len[i] = strlen(s + 1);
        r = min(r, len[i] * 2);
        rep(j, 1, len[i]) hash[i][j] = hash[i][j - 1] * BASE + s[j];
    }
    for (; l <= r; check(mid = (l + r) / 2) ? l = (ans = mid) + 1 : r = mid - 1);
    printf("%d\n", ans);
}

int main() {
    b[0] = 1;
    dep(i, 1, S) b[i] = b[i - 1] * BASE;
    for (read(t); t; --t) solve();
    return 0;
}
} // namespace SLV

int main() { return SLV::main(); }

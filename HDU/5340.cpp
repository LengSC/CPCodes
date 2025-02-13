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

    int t, p[N * 2], mid, maxr, cnt, n, l, r, pre[N], cntp, suf[N], cnts;
    char a[N], s[N * 2];

    void solve() {
        scanf("%s", a + 1);
        mid = maxr = cntp = cnts = 0, n = strlen(a + 1);
        s[0] = '$', s[cnt = 1] = '|';
        rep(i, 1, n) s[++cnt] = a[i], s[++cnt] = '|';
        s[++cnt] = '%';
        dep(i, 2, cnt) {
            p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > maxr) maxr = i + p[i], mid = i;
        }
        rep(i, 2, cnt - 2) {
            if (p[i] == i) pre[++cntp] = i;
            if (i + p[i] == cnt) suf[++cnts] = i;
        }
        rep(i, 1, cntp) rep(j, 1, cnts) {
            l = pre[i] + p[pre[i]];
            r = suf[j] - p[suf[j]];
            mid = (l + r) / 2;
            if (l > r || (l == r && s[mid] == '|')) continue;
            if (p[pre[i]] * 2 - 1 + p[mid] * 2 - 1 + p[suf[j]] * 2 - 1 >= cnt)
                return puts("Yes"), void();
        }
        puts("No");
    }

    int main() {
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

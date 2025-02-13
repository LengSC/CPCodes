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

    int t, n, mid, maxr, p[N * 2], sum[N * 2], cnt, w[26], ans, tmp, x, y;
    char a[N], s[N * 2];

    void solve() {
        dep(i, 0, 26) read(w[i]);
        scanf("%s", a + 1);
        mid = maxr = ans = 0, n = strlen(a + 1);
        s[0] = '$', s[cnt = 1] = '|';
        rep(i, 1, n) s[++cnt] = a[i], s[++cnt] = '|';
        rep(i, 2, cnt) {
            p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > maxr) maxr = i + p[i], mid = i;
        }
        rep(i, 2, cnt) sum[i] = sum[i - 1] + (s[i] == '|' ? 0 : w[s[i] - 'a']);
        for (int i = 3; i <= cnt - 2; i += 2) {
            tmp = 0;
            x = (1 + i) / 2, y = (i + cnt) / 2;
            if (x == p[x]) tmp += sum[i];
            if (cnt - y + 1 == p[y]) tmp += sum[cnt] - sum[i];
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }

    int main() {
        for (read(t); t; --t) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 1e5 + 2;

    int p[N * 2], cnt, l[N * 2], r[N * 2], ans;
    char a[N], s[N * 2];

    void manacher() {
        int mid = 0, maxr = 0;
        s[0] = '$', s[cnt = 1] = '|';
        rep(i, 1, strlen(a + 1)) s[++cnt] = a[i], s[++cnt] = '|';
        rep(i, 2, cnt) {
            p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > maxr) mid = i, maxr = i + p[i];
            l[i + p[i] - 1] = max(l[i + p[i] - 1], p[i] - 1);
            r[i - p[i] + 1] = max(r[i - p[i] + 1], p[i] - 1);
        }
    }

    int main() {
        scanf("%s", a + 1);
        manacher();
        for (int i = 3; i <= cnt; i += 2) r[i] = max(r[i], r[i - 2] - 2);
        for (int i = cnt; i >= 3; i -= 2) l[i] = max(l[i], l[i + 2] - 2);
        for (int i = 3; i <= cnt; i += 2)
            if (l[i] && r[i]) ans = max(ans, l[i] + r[i]);
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 2.2e7 + 2;

    int l, mid, maxr, ans, cnt, p[N];
    char a[N], s[N];

    int main() {
        scanf("%s", a + 1);
        l = strlen(a + 1);
        s[0] = '$', s[cnt = 1] = '|';
        rep(i, 1, l) s[++cnt] = a[i], s[++cnt] = '|';
        s[++cnt] = '%';
        rep(i, 2, cnt - 1) {
            if (i <= maxr) p[i] = min(p[mid * 2 - i], maxr - i + 1);
            else p[i] = 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > maxr) maxr = i + p[i] - 1, mid = i;
            ans = max(ans, p[i]);
        }
        printf("%d\n", ans - 1);
        return 0;
    }
}

int main() { return SLV::main(); }

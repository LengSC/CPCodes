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

    int t, l, mid, maxr, cnt, ans, p[N], a[N], s[N * 2];

    int manacher() {
        mid = maxr = ans = 0;
        s[0] = -1, s[cnt = 1] = 0;
        rep(i, 1, l) s[++cnt] = a[i], s[++cnt] = 0;
        dep(i, 2, cnt) {
            p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
            while (s[i - p[i]] == s[i + p[i]] && s[i - p[i]] <= s[i - p[i] + 2]) ++p[i];
            if (i + p[i] > maxr) maxr = i + p[i], mid = i;
            ans = max(ans, p[i]);
        }
        return ans - 1;
    }

    int main() {
        for (read(t); t; --t) {
            read(l); rep(i, 1, l) read(a[i]);
            printf("%d\n", manacher());
        }
        return 0;
    }
}

int main() { return SLV::main(); }

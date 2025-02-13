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

    int T, t, n, cnt, a[N], s[N * 2], p[N], ans;

    void manacher() {
        int mid = 0, maxr = 0;
        rep(i, 2, cnt) {
            p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > maxr) mid = i, maxr = i + p[i];
        }
    }

    int main() {
        read(T);
        rep(t, 1, T) {
            read(n);
            s[0] = -1919, s[cnt = 1] = -114514;
            rep(i, 1, n) read(s[++cnt]), s[++cnt] = -114514;
            s[cnt + 1] = -810;
            manacher();
            ans = 0;
            for (int i = 1; i <= cnt; i += 2)
                for (int j = i + p[i] - 1; j - i > ans; j -= 2)
                    if (j - i < p[j]) { ans = max(ans, j - i); break; }
            printf("Case #%d: %d\n", t, ans / 2 * 3);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

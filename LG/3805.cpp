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

    constexpr int N = 1.1e7 + 2;

    int p[N * 2];
    char a[N], s[N * 2];

    int manacher(const char *a, int la) {
        int res = 0, mid = 0, r = 0, cnt;
        s[0] = '$', s[cnt = 1] = '|';
        rep(i, 1, la) s[++cnt] = a[i], s[++cnt] = '|';
        rep(i, 2, cnt) {
            p[i] = i < r ? min(p[mid * 2 - i], r - i) : 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > r) mid = i, r = i + p[i];
            res = max(res, p[i]);
        }
        return res - 1;
    }

    int main() {
        scanf("%s", a + 1);
        printf("%d\n", manacher(a, strlen(a + 1)));
        return 0;
    }
}

int main() { return SLV::main(); }

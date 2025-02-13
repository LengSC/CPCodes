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

    int n, cnt, p[N * 2];
    char a[N], s[N * 2];

    int manacher() {
        int mid = 0, maxr = 0, res = 0;
        rep(i, 2, cnt) {
            p[i] = i < maxr ? min(p[mid * 2 - i], maxr - i) : 1;
            while (s[i - p[i]] == s[i + p[i]]) ++p[i];
            if (i + p[i] > maxr) {
                if (i % 2 == 1) {
                    dep(j, max(maxr, i + 4), i + p[i])
                        if ((j - i) % 4 == 0 && p[i - (j - i) / 2] > (j - i) / 2)
                            res = max(res, j - i);
                }
                mid = i, maxr = i + p[i];
            }
        }
        return res;
    }

    int main() {
        read(n); scanf("%s", a + 1);
        s[0] = '$', s[cnt = 1] = '|';
        rep(i, 1, n) s[++cnt] = a[i], s[++cnt] = '|';
        printf("%d\n", manacher());
        return 0;
    }
}

int main() { return SLV::main(); }

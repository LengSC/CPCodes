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

    int t, l, pi[N], j, per;
    char s[N];

    int main() {
        for (read(t); t; --t) {
            scanf("%s", s + 1);
            j = 0, l = strlen(s + 1);
            rep(i, 2, l) {
                while (j && s[i] != s[j + 1]) j = pi[j];
                if (s[i] == s[j + 1]) ++j;
                pi[i] = j;
            }
            per = l - pi[l];
            printf("%d\n", (l % (per = l - pi[l])) ? (per - l % per) : (per == l ? l : 0));
        }
        return 0;
    }
}

int main() { return SLV::main(); }

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

    constexpr int N = 1e6 + 2;

    int n, pi[N], f[N], ans[N], cnt;
    char s[N];

    int main() {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 2, j = 0; i <= n; ++i) {
            while (j && s[i] != s[j + 1]) j = pi[j];
            if (s[i] == s[j + 1]) ++j;
            pi[i] = j;
        }
        for (int i = n; i; i = pi[i]) ans[++cnt] = i;
        per(i, n, 1) {
            ++f[i];
            f[pi[i]] += f[i];
        }
        rep(i, 1, cnt) if (f[ans[i]] >= 3) {
            rep(j, 1, ans[i]) putchar(s[j]);
            return 0;
        }
        puts("Just a legend");
        return 0;
    }
}

int main() { return SLV::main(); }

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

    int pi[N], vis[26], l, j;
    char s[N];

    int main() {
        read(l);
        pi[0] = -1;
        rep(i, 1, l) {
            read(pi[i]); pi[i] = i - pi[i];
            if (pi[i]) s[i] = s[pi[i]];
            else {
                for (j = pi[i - 1]; ~j; j = pi[j]) vis[s[j + 1] - 'a'] = i;
                for (j = 0; j < 26; ++j) if (vis[j] != i) break;
                s[i] = j + 'a';
            }
        }
        puts(s + 1);
        return 0;
    }
}

int main() { return SLV::main(); }

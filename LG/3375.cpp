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

    int pi[N], la, lb, j;
    char a[N], b[N];

    int main() {
        scanf("%s %s", a + 1, b + 1);
        la = strlen(a + 1), lb = strlen(b + 1);
        rep(i, 2, lb) {
            while (j > 0 && b[i] != b[j + 1]) j = pi[j];
            if (b[i] == b[j + 1]) ++j;
            pi[i] = j;
        }
        j = 0;
        rep(i, 1, la) {
            while (j > 0 && a[i] != b[j + 1]) j = pi[j];
            if (a[i] == b[j + 1]) ++j;
            if (j == lb) printf("%d\n", i - lb + 1), j = pi[j];
        }
        rep(i, 1, lb) printf("%d ", pi[i]);
        return 0;
    }
}

int main() { return SLV::main(); }

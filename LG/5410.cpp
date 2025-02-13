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

    constexpr int N = 2e7 + 2;

    int la, lb, z[N], p[N];
    char a[N], b[N];
    ll ans;

    void zalgo(const char *b, int lb) {
        z[1] = lb;
        int l = 0, r = 0;
        rep(i, 2, lb) {
            if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
            while (i + z[i] <= lb && b[i + z[i]] == b[z[i] + 1]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
    }

    void exkmp(const char *a, int la, const char *b, int lb) {
        zalgo(b, lb);
        int l = 0, r = 0;
        rep(i, 1, la) {
            if (i <= r) p[i] = min(z[i - l + 1], r - i + 1);
            while (i + p[i] <= la && a[i + p[i]] == b[p[i] + 1]) ++p[i];
            if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
        }
    }

    int main() {
        scanf("%s%s", a + 1, b + 1);
        la = strlen(a + 1), lb = strlen(b + 1);
        exkmp(a, la, b, lb);
        rep(i, 1, lb) ans ^= (ll)i * (z[i] + 1);
        printf("%lld\n", ans);
        ans = 0;
        rep(i, 1, la) ans ^= (ll)i * (p[i] + 1);
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

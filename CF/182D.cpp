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

    int pia[N], pib[N], pera, perb, lena, lenb, ans;
    char a[N], b[N];
    bitset<N> vis;

    void pmt(const char *s, int *pi, int l) {
        int j = 0;
        rep(i, 2, l) {
            while (j && s[i] != s[j + 1]) j = pi[j];
            if (s[i] == s[j + 1]) ++j;
            pi[i] = j;
        }
    }

    int main() {
        scanf("%s %s", a + 1, b + 1);
        pmt(a, pia, lena = strlen(a + 1));
        pmt(b, pib, lenb = strlen(b + 1));
        pera = pia[lena], perb = pib[lenb];
        while (lena % (lena - pera)) pera = pia[pera];
        while (lenb % (lenb - perb)) perb = pib[perb];
        pera = lena - pera, perb = lenb - perb;
        if (pera != perb) return puts("0"), 0;
        rep(i, 1, pera) if (a[i] != b[i]) return puts("0"), 0;
        rep(i, 1, lena / pera) if (_i % i == 0) vis[i] = true;
        rep(i, 1, lenb / perb) if (_i % i == 0) ans += vis[i];
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

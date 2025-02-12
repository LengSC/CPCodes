#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
#define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    void read(T &x) {
        x = 0; char c = getchar(); bool f = false;
        while (!isdigit(c)) f = (c == '-'), c = getchar();
        while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
        if (f) x = -x;
    }

    template<typename T, typename ...Nxt>
    void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
}
using namespace IO;

namespace SLV {
    char s[10] = "`";
    int l, ans = 1;

    int C(int n, int m) {
        int res = 1;
        per(i, n, n - m + 1) res *= i;
        rep(i, 2, m) res /= i;
        return res;
    }
    
    int main() {
        scanf("%s", s + 1);
        l = strlen(s + 1);
        rep(i, 2, l) if (s[i] <= s[i - 1]) return puts("0"), 0;
        rep(i, 1, l - 1) ans += C(26, i);
        rep(i, 1, l)
            for (char j = s[i - 1] + 1; j < s[i]; ++j)
                ans += C('z' - j, l - i);
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }
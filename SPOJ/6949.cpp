#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
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
    } using namespace IO;

    constexpr int N = 5e4 + 2;

    int n, m, ans, cnt[37][37][37][37], t[5], comb[10][20];
    char s[6];

    int main() {
        rep(i, 0, 9) comb[i][0] = 1;
        rep(i, 1, 9) rep(j, 1, i) comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        read(n, m);
        rep(i, 1, n) {
            scanf("%s", s + 1);
            rep(j, 1, 4) t[j] = (isdigit(s[j]) ? s[j] - '0' + 1 : s[j] - 'a' + 11);
            rep(a, 0, 1) rep(b, 0, 1) rep(c, 0, 1) rep(d, 0, 1) {
                if (a + b + c + d < 4 - m) continue;
                ans += (((a + b + c + d) % 2 == (4 - m) % 2) ? 1 : -1) * comb[a + b + c + d][4 - m] * cnt[a * t[1]][b * t[2]][c * t[3]][d * t[4]];
                ++cnt[a * t[1]][b * t[2]][c * t[3]][d * t[4]];
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

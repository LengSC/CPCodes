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

    constexpr int MOD = 1000003;

    int T, n, m, f[55][1 << 16], match[55][30], len, lim, ans;
    char str[20][55];

    /**
     * f[i][j]: 对于前 i 位字符，匹配状态为 j 的方案数
     * match[i][ch]: 对于第 i 位字符，匹配字符 ch 的状态
     */

    void solve() {
        read(n, m);
        rep(i, 1, n) scanf("%s", str[i] + 1);
        
        memset(f, 0, sizeof(f));
        memset(match, 0, sizeof(match));
        ans = 0;
        lim = (1 << n) - 1;
        len = strlen(str[1] + 1);
        f[0][lim] = 1;

        rep(i, 1, len)
            rep(ch, 0, 25)
                rep(k, 1, n)
                    if (str[k][i] == ch + 'a' || str[k][i] == '?')
                        match[i][ch] |= (1 << (k - 1));

        rep(i, 1, len)
            rep(j, 0, lim)
                if (f[i - 1][j])
                    rep(ch, 0, 25)
                        f[i][match[i][ch] & j] = (f[i][match[i][ch] & j] + f[i - 1][j]) % MOD;
        
        rep(i, 0, lim)
            if (__builtin_popcount(i) == m)
                ans = (ans + f[len][i]) % MOD;
        
        printf("%d\n", ans);
    }

    int main() {
        for (read(T); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

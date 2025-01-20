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

    ll n, k, a[16], cnt, ans;
    
    void dfs(ll cur, ll num, ll sign) {
        ans += n / num * sign;
        rep(i, cur + 1, cnt)
            if (num / __gcd(num, a[i]) * a[i] <= n)
                dfs(i, num / __gcd(num, a[i]) * a[i], -sign);
    }
    
    int main() {
        read(n, k);
        rep(i, 1, k) read(a[i]);
        sort(a + 1, a + 1 + k);
        rep(i, 1, k) if (a[i]) {
            a[++cnt] = a[i];
            rep(j, i + 1, k) if (a[j] % a[i] == 0) a[j] = 0;
        }
        reverse(a + 1, a + 1 + cnt);
        dfs(0, 1, 1);
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

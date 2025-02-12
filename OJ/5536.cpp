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

    ll l, r, a[2050], b[2050], cnta = -1, cntb, ilgl;

    ll gcd(ll a, ll b) {
        if (!b) return a;
        return gcd(b, a % b);
    }

    void dfs1(ll cur) {
        if (cur > r) return;
        a[++cnta] = cur, dfs1(cur * 10 + 2), dfs1(cur * 10 + 9);
    }

    void dfs2(ll cur, ll num, ll sign) {
        ilgl += (r / num - l / num) * sign;
        cerr << ilgl << endl;
        rep(i, cur + 1, cntb)
            if (num / gcd(num, b[i]) * b[i] <= r)
                dfs2(i, num / gcd(num, b[i]) * b[i], -sign);
    }

    int main() {
        read(l, r), --l;
        dfs1(0);
        rep(i, 1, cnta) if (a[i]) {
            b[++cntb] = a[i];
            rep(j, i + 1, cnta) if (a[j] % a[i] == 0) a[j] = 0;
        }
        reverse(b + 1, b + 1 + cntb);
        dfs2(0, 1, 1);
        printf("%lld\n", r - l - ilgl);
        return 0;
    }
}

int main() { return SLV::main(); }

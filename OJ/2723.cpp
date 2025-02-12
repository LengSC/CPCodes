#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    using namespace std;
    // using ll = long long;
    using ll = __int128;
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
        template<typename T>
        void print(T x) {
            static char c[50], top = 0;
            while (x) c[++top] = x % 10, x /= 10;
            while (top) putchar(c[top] + 48), --top;
            putchar('\n');
        }
    } using namespace IO;

    ll l, r, a[2050], b[2050], cnta = -1, cntb, ilgl; // ilgl: cnt illegal

    ll gcd(ll a, ll b) {
        if (!b) return a;
        return gcd(b, a % b);
    }

    void dfs1(ll x) {
        if (x > r) return;
        a[++cnta] = x, dfs1(x * 10 + 6), dfs1(x * 10 + 8);
    }

    void dfs2(ll cur, ll num, ll sign) {
        ilgl += (r / num - l / num) * sign;
        rep(i, cur + 1, cntb)
            if (num / gcd(num, b[i]) * b[i] <= r) // i.e. lcm(num, b[i])
                dfs2(i, num / gcd(num, b[i]) * b[i], -sign);
    }

    int main() {
        read(l, r), --l;
        dfs1(0); // a[] is already sorted
        rep(i, 1, cnta) if (a[i]) {
            b[++cntb] = a[i];
            rep(j, i + 1, cnta) if (a[j] % a[i] == 0) a[j] = 0;
        }
        reverse(b + 1, b + 1 + cntb);
        dfs2(0, 1, 1);
        print(r - l - ilgl);
        return 0;
    }
}

int main() { return SLV::main(); }

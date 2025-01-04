#include <bits/stdc++.h>

namespace SLV {
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
    } using namespace IO;

    constexpr int N = 5e4 + 2;

    int T, k, s;

    namespace SGT {
        #define lc (cur << 1)
        #define rc (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        int tr[N << 2];

        void build(int cur, int l, int r) {
            if (l == r) return tr[cur] = 1, void();
            build(lc, l, mid), build(rc, mid + 1, r);
            tr[cur] = tr[lc] + tr[rc];
        }

        int query(int cur, int l, int r, int x) {
            --tr[cur];
            if (l == r) return l;
            return (tr[lc] >= x) ? query(lc, l, mid, x) : query(rc, mid + 1, r, x - tr[lc]);
        }
    }

    void solve() {
        read(k);
        SGT::build(1, 1, k);
        rep(i, 1, k) {
            read(s);
            printf("%d%c", SGT::query(1, 1, k, s + 1), " \n"[i == k]);
        }
    }


    int main() {
        for (read(T); T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }
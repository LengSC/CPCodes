#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
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

    constexpr int N = 1e5 + 5;

    ll n, k, a[N];

    namespace SGT {
        #define ls (tr[cur].lson)
        #define rs (tr[cur].rson)
        #define mid ((l + r) >> 1)
        struct Node {
            ll lson, rson, maxn, cnt;
        } tr[N << 4];

        ll tot = 0, root = 0;

        void up(ll cur) {
            tr[cur].maxn = max(tr[ls].maxn, tr[rs].maxn);
        }

        void modify(ll &cur, ll l, ll r, ll x, ll v) {
            if (!cur) cur = ++tot;
            if (l == r) {
                tr[cur].cnt += v;
                if (tr[cur].cnt == 1) tr[cur].maxn = l;
                else tr[cur].maxn = 0;
                return;
            }
            if (x <= mid) modify(ls, l, mid, x, v);
            else modify(rs, mid + 1, r, x, v);
            up(cur);
        }
        #undef ls
        #undef rs
        #undef mid
    }

    signed main() {
        read(n, k);
        rep(i, 1, n) read(a[i]);
        dep(i, 1, k) SGT::modify(SGT::root, 0, 2e9, a[i] + 1e9, 1);
        rep(i, 1, n - k + 1) {
            SGT::modify(SGT::root, 0, 2e9, a[i + k - 1] + 1e9, 1);
            if (SGT::tr[SGT::root].maxn) printf("%ld\n", SGT::tr[SGT::root].maxn - (ll)1e9);
            else puts("Nothing");
            SGT::modify(SGT::root, 0, 2e9, a[i] + 1e9, -1);
        }
        return 0;
    }
}

int main() { return SLV::main(); }

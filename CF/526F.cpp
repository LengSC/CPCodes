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

    constexpr int N = 3e5 + 2;

    ll n, a[N], sufmax[N], topmx, sufmin[N], topmn, ans;
    unordered_map<ll, ll> pos;

    namespace SGT {
        #define ls (cur << 1)
        #define rs (cur << 1 | 1)
        #define mid ((l + r) >> 1)
        struct Node {
            ll minn, cnt, add;
        } tr[N << 2];

        void uNode(int cur, ll v) {
            tr[cur].minn += v;
            tr[cur].add += v;
        }

        void down(int cur) {
            if (tr[cur].add) uNode(ls, tr[cur].add), uNode(rs, tr[cur].add), tr[cur].add = 0;
        }

        void up(int cur) {
            tr[cur].minn = min(tr[ls].minn, tr[rs].minn);
            tr[cur].cnt = (tr[cur].minn == tr[ls].minn ? tr[ls].cnt : 0) + (tr[cur].minn == tr[rs].minn ? tr[rs].cnt : 0);
        }

        void build(int cur, int l, int r) {
            tr[cur].cnt = r - l + 1;
            if (l == r) return;
            build(ls, l, mid), build(rs, mid + 1, r);
        }

        void uAdd(int cur, int l, int r, int ql, int qr, ll v) {
            if (ql <= l && r <= qr) return uNode(cur, v);
            if (qr < l || ql > r) return;
            down(cur);
            uAdd(ls, l, mid, ql, qr, v), uAdd(rs, mid + 1, r, ql, qr, v);
            up(cur);
        }
        #undef ls
        #undef rs
        #undef mid
    }

    int main() {
        read(n);
        rep(i, 1, n) read(a[0]), read(a[a[0]]);
        SGT::build(1, 1, n);
        rep(i, 1, n) {
            while (topmx && a[sufmax[topmx]] < a[i]) SGT::uAdd(1, 1, n, sufmax[topmx - 1] + 1, sufmax[topmx], -a[sufmax[topmx]]), --topmx;
            while (topmn && a[sufmin[topmn]] > a[i]) SGT::uAdd(1, 1, n, sufmin[topmn - 1] + 1, sufmin[topmn], a[sufmin[topmn]]), --topmn;
            SGT::uAdd(1, 1, n, pos[a[i]] + 1, i, -1), pos[a[i]] = sufmax[++topmx] = sufmin[++topmn] = i;
            SGT::uAdd(1, 1, n, sufmax[topmx - 1] + 1, i, a[i]);
            SGT::uAdd(1, 1, n, sufmin[topmn - 1] + 1, i, -a[i]);
            ans += SGT::tr[1].cnt;
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

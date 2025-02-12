#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (int i = st, e##i = ed; i >= e##i; --i)

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

constexpr int N = 1e5 + 2;

namespace SGT {
    #define lc (cur << 1)
    #define rc (cur << 1 | 1)
    #define mid ((l + r) >> 1)
    struct {
        struct {
            int l, r, sum, add;
        } tr[N << 2];

        void down(int cur) {
            if (!tr[cur].add) return;
            tr[lc].sum += tr[cur].add * (tr[lc].r - tr[lc].l + 1);
            tr[lc].add += tr[cur].add;
            tr[rc].sum += tr[cur].add * (tr[rc].r - tr[rc].l + 1);
            tr[rc].add += tr[cur].add;
            tr[cur].add = 0;
        }

        void up(int cur) {
            tr[cur].sum = tr[lc].sum + tr[rc].sum;
        }

        void build(int cur, int l, int r) {
            tr[cur].l = l, tr[cur].r = r;
            if (l == r) return;
            build(lc, l, mid);
            build(rc, mid + 1, r);
        }

        void uAdd(int cur, int l, int r, int v) {
            if (tr[cur].r < l || tr[cur].l > r) return;
            if (l <= tr[cur].l && tr[cur].r <= r)
                return tr[cur].sum += v * (tr[cur].r - tr[cur].l + 1),
                tr[cur].add += v,
                void();
            down(cur);
            uAdd(lc, l, r, v);
            uAdd(rc, l, r, v);
            up(cur);
        }

        int qSum(int cur, int l, int r) {
            if (tr[cur].r < l || tr[cur].l > r) return 0;
            if (l <= tr[cur].l && tr[cur].r <= r) return tr[cur].sum;
            down(cur);
            return qSum(lc, l, r) + qSum(rc, l, r);
        }
    } st;
    #undef lc
    #undef rc
    #undef mid
};
using namespace SGT;

namespace SLV {
    int n, m, x, y;
    char op[4];

	int main() {
        read(n, m);
        st.build(1, 1, n);
        rep(i, 1, m) {
            scanf("%s", op), read(x, y);
            switch (op[1]) {
                case 'd': st.uAdd(1, x, x, y); break;
                case 'u': st.uAdd(1, x, x, -y); break;
                default: printf("%d\n", st.qSum(1, x, y));
            }
        }
		return 0;
	}
}

int main() { return SLV::main(); }

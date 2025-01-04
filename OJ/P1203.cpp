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

constexpr int N = 6e4 + 2, INF = 0x3f3f3f3f;

int c, s, r, o, d, n;

namespace SGT {
	#define lc (cur << 1)
	#define rc (cur << 1 | 1)
	#define mid ((l + r) >> 1)
	struct {
		struct {
			int l, r, min, sub;
		} tr[N << 2];

		void down(int cur) {
			if (!tr[cur].sub) return;
			tr[lc].min -= tr[cur].sub;
			tr[lc].sub += tr[cur].sub;
			tr[rc].min -= tr[cur].sub;
			tr[rc].sub += tr[cur].sub;
			tr[cur].sub = 0;
		}

		void up(int cur) {
			tr[cur].min = min(tr[lc].min, tr[rc].min);
		}

		void build(int cur, int l, int r) {
			tr[cur].l = l, tr[cur].r = r;
			tr[cur].min = s;
			if (l == r) return;
			build(lc, l, mid), build(rc, mid + 1, r);
		}

		void uSub(int cur, int l, int r, int v) {
			if (tr[cur].r < l || tr[cur].l > r) return;
			if (l <= tr[cur].l && tr[cur].r <= r)
				return tr[cur].min -= v, tr[cur].sub += v, void();
			down(cur);
			uSub(lc, l, r, v);
			uSub(rc, l, r, v);
			up(cur);
		}

		int qMin(int cur, int l, int r) {
			if (tr[cur].r < l || tr[cur].l > r) return INF;
			if (l <= tr[cur].l && tr[cur].r <= r) return tr[cur].min;
			down(cur);
			return min(qMin(lc, l, r), qMin(rc, l, r));
		}
	} st;
	#undef lc
	#undef rc
	#undef mid
}
using namespace SGT;

namespace SLV {
	int main() {
		read(c, s, r);
		st.build(1, 1, c);
		rep(i, 1, r) {
			read(o, d, n);
			if (st.qMin(1, o + 1, d) >= n) st.uSub(1, o + 1, d, n), puts("YES");
			else puts("NO");
		}
		return 0;
	}
}

int main() { return SLV::main(); }
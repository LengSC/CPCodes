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

namespace SLV {
	constexpr int N = 20;
	
	struct {
		int c, p, l;
	} s[N];
	int n, mx = 0;
	
	int exgcd(int a, int b, int &x, int &y) {
		if (b == 0) return x = 1, y = 0, a;
		int d = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
	
	bool check(int m) {
		/**
		 * true -> '(p[i]-p[j])*x - m*y = c[j] - c[i]' not exist
		 **/
		rep(i, 1, n) rep(j, i + 1, n) {
			int a = s[i].p - s[j].p, b = m, c = s[j].c - s[i].c;
			if (a < 0) a = -a, c = -c;
			int x, y, d = exgcd(a, b, x, y);
			if (c % d == 0) {
				x = x * (c / d);
				b /= d;
//				if (b < 0) b = -b;
				x = (x % b + b) % b;
				if (x <= min(s[i].l, s[j].l)) return false;
			}
		}
		return true;
	}

	int main() {
		read(n);
		rep(i, 1, n) read(s[i].c, s[i].p, s[i].l), mx = max(mx, s[i].c);
		rep(i, mx, 1e6) if (check(i)) return printf("%d\n", i), 0;
		return 0;
	}
}

int main() { return SLV::main(); }

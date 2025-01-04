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

int n, a0, a1, b0, b1, cnt;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	for (read(n); n; --n) {
		read(a0, a1, b0, b1);
		/* gcd(x, a0) == a1
		   lcm(x, b0) == b1 */
		cnt = 0;
		for (int i = 1, x; i * i <= b1; ++i) {
			if (b1 % i == 0) {
				x = i;
				if (x % a1 == 0)
					if (gcd(a0, x) == a1 && gcd(x, b0) * b1 == x * b0) ++cnt;
				x = b1 / i;
				if (x != i && x % a1 == 0)
					if (gcd(a0, x) == a1 && gcd(b1 / b0, b1 / x) == 1) ++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

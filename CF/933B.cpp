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

ll p, k, d, a[10005];

/**
 * f(x) = q(x) * (x + k) + p
 * ... ==> p = sigma(i, 0, d-1){ (-k)^i*a[i] }
 **/

int main() {
	read(p, k);
	k = -k;
	while (p) {
		a[++d] = p % k, p /= k;
		if (a[d] < 0) a[d] -= k, ++p;
	}
	printf("%lld\n", d);
	rep(i, 1, d) printf("%lld ", a[i]);
	return 0;
}

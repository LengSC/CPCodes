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

constexpr int N = 1e6 + 2;

int b, q;
ll k, sum, a[N];

/**
 *     (b - 1) | X
 * ==> (b - 1) | sum of each number of X
 **/

int main() {
	read(b, q);
	rep(i, 0, b - 1) read(a[i]), sum += i * a[i];
	if (sum % (b - 1) != 0) --a[sum % (b - 1)];
	rep(i, 1, b - 1) a[i] += a[i - 1];
	rep(i, 1, q) {
		read(k);
		if (k >= a[b - 1]) puts("-1");
		else printf("%d\n", upper_bound(a, a + b, k) - a);
	}
	return 0;
}

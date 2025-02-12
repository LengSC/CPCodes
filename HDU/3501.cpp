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

constexpr int MOD = 1e9 + 7;

ll n;

ll phi(ll n) {
	ll res = n;
	rep(i, 2, sqrt(n))
		if (n % i == 0) {
			res = res / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) res = res / n * (n - 1);
	return res;
}

int main() {
	for (;;) {
		read(n);
		if (n == 0) break;
		/* n * (n - 1) / 2 - n * phi(n) / 2 */
		printf("%lld\n", (n - 1 - phi(n)) % MOD * n / 2 % MOD);
	}
	return 0;
}

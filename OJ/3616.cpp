#include <bits/stdc++.h>
#define rep(i, st, ed) for (ll i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (ll i = st, e##i = ed; i >= e##i; --i)

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

ll a, b, c, k, x, y, ans, t;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) return x = 1, y = 0, a;
	ll d = exgcd(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - a / b * y;
	return d;
}

/* c*x + 2^k*y = b-a */

int main() {
	for(;;) {
		read(a, b, c, k);
		if (!(a | b | c | k)) break;
		ll n = 1ll << k, d = exgcd(c, n, x, y);
		b -= a;
		if (b % d != 0) printf("FOREVER\n");
		else {
			ans = b / d * x, t = n / d;
			printf("%lld\n", (ans % t + t) % t);
		}
	}
	return 0;
}

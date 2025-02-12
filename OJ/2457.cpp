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
	ll n, m, l;
	
	/**
	 * each shuffle: x <- 2 * x % (n + 1)
	 * => x * 2^m === l (mod n+1)
	 * => x === l * inv(2)^m (mod n+1)
	 **/

	ll qmul(ll a, ll b, ll p) {
		ll res = 0;
		for (; b; b >>= 1) {
			if (b & 1) res = (res + a) % p;
			a = (a + a) % p;
		}
		return res;
	}
	
	ll qpow(ll a, ll b, ll p) {
		ll res = 1;
		for (; b; b >>= 1) {
			if (b & 1) res = qmul(res, a, p);
			a = qmul(a, a, p);
		}
		return res;
	}

	int main() {
		read(n, m, l);
		// inv(2) = n / 2 + 1;
		++n;
		printf("%lld\n", qmul(l, qpow(n / 2 + 1, m, n), n));
		return 0;
	}
}

int main() { return SLV::main(); }
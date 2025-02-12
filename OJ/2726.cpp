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
	constexpr int MOD = 20100403;
	int n, m;

	ll qpow(ll a, ll b) {
		ll res = 1;
		for (; b; a = a * a % MOD, b >>= 1)
			if (b & 1) res = res * a % MOD;
		return res;
	}

	ll c(ll n, ll m) {
		ll sum = 1, inv = 1;
		rep(i, 1, m) {
			sum = sum * (n - i + 1) % MOD;
			inv = inv * i % MOD;
		}
		inv = qpow(inv, MOD - 2);
		return sum * inv % MOD;
	}

	ll lucas(ll n, ll m) {
		if (!m) return 1;
		return lucas(n / MOD, m / MOD) * c(n % MOD, m % MOD) % MOD;
	}

	int main() {
		read(n, m);
		/**
		 * ans = C(n + m, m) - C(n + m, m - 1)
		 */
		printf("%lld\n", ((lucas(n + m, m) - lucas(n + m, m - 1)) % MOD + MOD) % MOD);
		return 0;
	}
}

int main() { return SLV::main(); }

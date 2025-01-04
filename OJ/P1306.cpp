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
	constexpr int MOD = 9901;
	ll a, b, cnt, ans = 1;
	
	ll qpow(ll a, ll b) {
		ll res = 1;
		for (; b; b >>= 1) {
			if (b & 1) res = res * a % MOD;
			a = a * a % MOD;
		}
		return res;
	}
	
	ll f(ll a, ll b) {
		/* sigma(i, 0, b) a^i */
		if (!b) return 1;
		if (b & 1) return (1 + qpow(a, b / 2 + 1)) * f(a, b / 2) % MOD;
		return ((1 + qpow(a, b / 2 + 1)) * f(a, b / 2 - 1) % MOD + qpow(a, b / 2)) % MOD;
	}
	
	int main() {
		read(a, b);
		rep(i, 2, sqrt(a)) {
			if (a % i) continue;
			cnt = 0;
			while(!(a % i)) a /= i, ++cnt;
			ans = ans * f(i, cnt * b) % MOD;
		}
		if (a != 1) ans = (ans * f(a, b)) % MOD;
		printf("%lld\n", ans);
		return 0;
	}
}

int main() { return SLV::main(); }

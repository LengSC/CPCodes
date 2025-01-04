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
	constexpr int N = 5e6 + 5, p = 1e9 + 7, k = 998244353;
	ll n, a[N], s[N], invs[N], ans, las = 1;
	
	void exgcd(ll a, ll b, ll &x, ll &y) {
		if (!b) return x = 1, y = 0, void();
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
	
	int main() {
		read(n);
		s[0] = 1;
		rep(i, 1, n) read(a[i]), s[i] = s[i - 1] * a[i] % p;
		exgcd(s[n], p, invs[n], invs[0]);
		invs[n] = (invs[n] % p + p) % p;
		per(i, n, 2) invs[i - 1] = invs[i] * a[i] % p;
		per(i, n, 1) {
			ans = (ans + invs[i] * s[i - 1] % p * las % p) % p;
			las = las * k % p;
		}
		printf("%lld\n", ans);
		return 0;
	}
}

int main() { return SLV::main(); }

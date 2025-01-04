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

constexpr ll N = 1e6 + 10, MOD = 1e9 + 7;

ll n, fac[N], pr[N], cnt, a[N], ans = 1;

void pre(ll n) {
	rep(i, 2, n) {
		if (!fac[i]) fac[i] = i, pr[++cnt] = i;
		rep(j, 1, cnt) {
			if (i * pr[j] > n) break;
			fac[i * pr[j]] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
}

int main() {
	read(n);
	pre(n);
	for (ll i = 2, p; i <= n; ++i) {
		if (fac[i] != i) continue;
		p = 1;
		for (;;) {
			p *= i, a[i] += n / p;
			if (p > n) break;
		}
	}
	rep(i, 2, n) ans = (ans * (2 * a[i] + 1)) % MOD;
	printf("%lld\n", ans);
	return 0;
}

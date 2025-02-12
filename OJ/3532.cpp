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

ll a, b, x, y;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}

int main() {
	read(a, b);
	exgcd(a, b, x, y);
	printf("%lld\n", (x + b) % b);
	return 0;
}

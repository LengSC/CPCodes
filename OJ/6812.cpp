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
	constexpr int N = 3e6 + 5;
	int n, p, inv[N];
	
	int main() {
		read(n, p);
		inv[1] = 1;
		rep(i, 2, n) inv[i] = ((ll)p - p / i) * inv[p % i] % p;
		rep(i, 1, n) printf("%d\n", inv[i]);
		return 0;
	}
}

int main() { return SLV::main(); }

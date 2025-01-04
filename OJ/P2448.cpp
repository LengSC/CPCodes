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
	constexpr int N = 2e9 + 5;
	
	int n;
	set<int> ans = {1};
	
	int main() {
		read(n);
		if (n == 1) return printf("None\n"), 0;
		rep(a, 1, sqrt(n)) { /* a * b == n */
			if (n % a == 0) {
			   int b = n / a;
			   for (ll x = b + 1; x <= n; x += b) if ((x + 1) % a == 0) ans.emplace(x);
			   for (ll x = b - 1; x <= n; x += b) if ((x - 1) % a == 0) ans.emplace(x);
			}
		}
		for (const auto &i: ans) printf("%d\n", i);
		return 0;
	}
}

int main() { return SLV::main(); }

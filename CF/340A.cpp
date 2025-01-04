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
	
	void bios() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	}
}
using namespace IO;

int x, y, a, b, l;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	read(x, y, a, b);
	l = x * y / gcd(x, y);
	printf("%d\n", b / l - (a - 1) / l);
	return 0;
}

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

constexpr int N = 1e6 + 5;
int n, a, b, p, m, l[N], r[N], s[N << 1], d[N << 1], cnt, ans;
char c;

int main() {
	read(n, a, b, p, m);
	while (!isdigit(c)) c = getchar();
	rep(i, 1, m) {
		int rem = (i * a + b) % n;
		if (c == '1') /* p <= a*i+b <= n-1 */
			l[i] = p - 1 - rem, r[i] = n - 1 - rem, l[i] < 0 && (l[i] += n);
		else /* 0 <= a*i+b <= p-1 */
			l[i] = n - 1 - rem, r[i] = p - 1 - rem, r[i] < 0 && (r[i] += n);
		if (i < m) c = getchar();
	}
	return 0;
}

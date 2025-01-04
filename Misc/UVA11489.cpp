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
		while (isdigit(c)) x = (x << 1) +(x << 3) + (c ^ 48), c = getchar();
		if (f) x = -x;
	}
	
	template<typename T, typename ...Nxt>
	void read(T &x, Nxt &...nxt) { read(x), read(nxt...); }
}
using namespace IO;

int t, q[3];
char s[1005];

int main() {
	read(t);
	rep(j, 1, t) {
		scanf("%s", s);
		memset(q, 0, sizeof(q));
		rep(i, 0, strlen(s)) ++q[(s[i] - '0') % 3];
		printf("Case %d: %c\n", j, ((q[(q[1] + q[2] * 2) % 3]) <= 0 || q[0] % 2 == 0) ? 'T' : 'S');
	}
	return 0;
}

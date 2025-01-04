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

int n;
char const *suf[] = {
	"050",
	"080",
	"170",
	"020",
	"200",
	"110"
};

int main() {
	read(n);
	if (n < 3) puts("-1");
	else if (n == 3) puts("210");
	else {
		printf("1");
		rep(i, 1, n - 4) printf("0");
		printf("%s\n", suf[(n - 4) % 6]);
	}
	return 0;
}

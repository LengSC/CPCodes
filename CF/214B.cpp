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

constexpr int N = 1e5 + 2;

int n, a, cnt[10], sum;
bool flg;

int main() {
	read(n);
	rep(i, 1, n) {
		read(a);
		sum += a;
		++cnt[a];
	}
	if (cnt[0] == 0) puts("-1");
	else {
		sum %= 3;
		if (sum == 1) {
			for (int i = 1; i <= 9; i += 3)
				if (cnt[i]) {
					--cnt[i], sum = 0;
					break;
				}
		} else if (sum == 2) {
			for (int i = 2; i <= 9; i += 3)
				if (cnt[i]) {
					--cnt[i], sum = 0;
					break;
				}
		}
		if (sum) {
			for (int i = 1; i < 9 && sum != 0;) {
//				cerr << i << " " <<sum <<endl;
				if (cnt[i] == 0 || i % 3 == 0) ++i;
				else {
					--cnt[i], sum -= i % 3;
					if (sum < 0) sum += 3;
				}
			}
		}
		per(i, 9, 1)
			rep(j, 1, cnt[i])
				printf("%d", i), flg = true;
		if(flg) {
			rep(i, 1, cnt[0]) printf("0");
		} else {
			puts("0");
		}
	}
	return 0;
}

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

constexpr int N = 1e8 + 5;

vector<int> primes;
bool notPrime[N];

void pre(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!notPrime[i])
			primes.emplace_back(i);
		for (auto &j: primes) {
			if (i * j > n) break;
			notPrime[i * j] = true;
			if (i % j == 0) break;
		}
	}
}

int n, q, k;

int main() {
	read(n, q);
	pre(n);
	rep(i, 1, q) {
		read(k);
		printf("%d\n", primes[k - 1]);
	}
	return 0;
}

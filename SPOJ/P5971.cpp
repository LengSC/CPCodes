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

constexpr int N = 1e6 + 2;

/* https://oi-wiki.org/math/number-theory/mobius/#spoj-5971lcmsum */

int n, t, pr[N], cnt;
ll g[N];
bool v[N];

void pre() {
	g[1] = 1;
	rep(i, 2, N - 1) {
		if (!v[i]) {
			pr[++cnt] = i;
			g[i] = (ll)1 * i * (i - 1) + 1;
		}
		for (int j = 1; j <= cnt && i * pr[j] < N; ++j) {
			v[i * pr[j]] = true;
			if (i % pr[j] == 0) {
				g[i * pr[j]] = g[i] + (g[i] - g[i / pr[j]]) * pr[j] * pr[j];
				break;
			}
			g[i * pr[j]] = g[i] * g[pr[j]];
		}
	}
}

int main() {
	pre();
//	rep(i, 1, 100) cerr << g[i] <<" ";
	for (read(t); t; --t) {
		read(n);
		printf("%lld\n", (g[n] + 1) * n / 2);
	}
	return 0;
}

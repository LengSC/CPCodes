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

int k;
vector<int> pr, ans;
bool np[N];

void pre() {
	for (int i = 2; i <= N; ++i) {
		if (!np[i]) pr.emplace_back(i);
		for (const auto &j: pr) {
			if (i * j > N) break;
			np[i * j] = true;
			if (i % j == 0) break;
		}
	}
}

bool cs(int x) {
	if (x == 1) return false;
	if (x < N) return !np[x];
	rep(i, 2, sqrt(x))
		if (x % i == 0) return false;
	return true;
}

void dfs(int rest, int p, int cur) {
	/**
	 * @param rest: rest of sum of factors
	 * @param p: id of current prime
	 * @param cur: current mul
	 **/
	if (rest == 1) return ans.emplace_back(cur), void();
	if (cs(rest - 1) && rest > pr[p]) ans.emplace_back(cur * (rest - 1));
	for (int i = p, t; pr[i] * pr[i] <= rest; ++i) {
		t = pr[i];
		for (int sum = t + 1; sum <= rest; t *= pr[i], sum += t)
			if (rest % sum == 0)
				dfs(rest / sum, i + 1, cur * t);
	}
}

int main() {
	pre();
	while (~scanf("%d", &k)) {
		ans.clear();
		dfs(k, 0, 1);
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (const auto &i: ans) printf("%d ", i);
		if (!ans.empty()) puts("");
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (int i = st, e##i = ed; i >= e##i; --i)
#define fi first
#define se second

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
	constexpr int N = 1e9 + 5, M = 2e5 + 5;
	int t, n, a[M], b[M], ans[M], v, g, x, y;
	unordered_map<int, vector<int>> c;
	unordered_set<int> h;
	
	int exgcd(int a, int b, int &x, int &y) {
		if (!b) return x = 1, y = 0, a;
		int d = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
	
	void solve(const vector<int> &d) {
		if (d.size() < 2)
			return ans[d[0]] = t / g, void();
		vector<pair<ll, int>> f;
		f.emplace_back(0, d[0]);
		rep(i, 1, d.size() - 1) {
			int p = (b[d[i]] - b[d[0]] + t) % t;
			ll tx = (ll)p / g * x;
			if (tx < 0) tx += t / g * ((-tx) / (t / g) + 1);
			f.emplace_back(tx % (t / g), d[i]);
		}
		sort(f.begin(), f.end());
		rep(i, 1, f.size() - 1) ans[f[i - 1].se] = f[i].fi - f[i - 1].fi;
		ans[f.back().se] = t / g - f.back().fi;
	}
	
	int main() {
		read(t, n);
		rep(i, 0, n - 1) read(a[i]), v = (v + a[i]) % t;
		rep(i, 1, n - 1) b[i] = (a[i] + b[i - 1]) % t;
		g = __gcd(v, t);
		exgcd(v, t, x, y);
		rep(i, 0, n - 1)
			if (h.find(b[i]) == h.end())
				c[b[i] % g].emplace_back(i), h.emplace(b[i]);
		for (auto [i, d]: c) solve(d);
		rep(i, 0, n - 1) printf("%d ", ans[i]);
		puts("");
		return 0;
	}
}

int main() { return SLV::main(); }

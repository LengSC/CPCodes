#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st; i <= ed; ++i)
#define per(i, st, ed) for (int i = st; i >= ed; --i)

using namespace std;

string n;
int cnt[10], sum;

int main() {
	cin >> n;
	for (const auto &i: n) {
		++cnt[i - '0'];
		sum += (i - '0');
	}
	if (cnt[0] == 0 || sum % 3 != 0) printf("-1");
	else
		per(i, 9, 0)
			rep(j, 1, cnt[i]) printf("%d", i);
	puts("");
	return 0;
}

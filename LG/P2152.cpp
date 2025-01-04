#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (int i = st, e##i = ed; i >= e##i; --i)

using namespace std;

constexpr int N = 1e4 + 10, BASE = 1e9;

struct Big {
	int len, n[N / 9 + 10];
	
	Big() = default;
	Big(char *s){
		int sl = strlen(s), p = sl - 1;
		len = sl / 9 + (sl % 9 ? 1 : 0);
		rep(i, 1, len) {
			n[i] = 0;
			per(j, min(p, 8), 0) n[i] = n[i] * 10 + (s[p - j] & 15);
			p -= 9;
		}
	}
	
	bool isZero() {
		return len == 1 && n[1] == 0;
	}
	
	bool is2() {
		return !isZero() && !(n[1] & 1);
	}
	
	bool operator < (const Big &b) {
		if (len != b.len) return len < b.len;
		per(i, len, 1)
			if (n[i] != b.n[i]) return n[i] < b.n[i];
		return false;
	}
	
	bool operator -= (const Big &b) {
		rep(i, 1, len) {
			if (i <= b.len) {
				n[i] -= b.n[i];
				if (n[i] < 0) --n[i + 1], n[i] += BASE;
			}
		}
		for (; !n[len] && len > 1; --len);
		return isZero();
	}
	
	void div2() {
		rep(i, 1, len) {
			if (n[i] & 1) n[i - 1] += BASE >> 1;
			n[i] >>= 1;
		}
		for (; !n[len] && len > 1; --len);
	}
	
	void operator <<= (const int &x) {
		rep(t, 1, x) {
			n[len + 1] = 0;
			per(i, len, 1)
				n[i] <<= 1, n[i + 1] += n[i] / BASE, n[i] %= BASE;
			if (n[len + 1]) ++len;
		}
		this->print();
	}
	
	void print() {
		per(i, len, 1)
			if (i == len) printf("%d", n[i]);
			else printf("%09d", n[i]);
		puts("");
	}
} x, y;

char a[N], b[N];
int lx, ly;

int main() {
	scanf("%s %s", a, b);
	x = Big(a), y = Big(b);
	if (x.isZero()) return y.print(), 0;
	if (y.isZero()) return x.print(), 0;
	for (; x.is2(); ++lx) x.div2();
	for (; y.is2(); ++ly) y.div2();
	for (;;) {
		if (!(x < y)) {
			if (x -= y) return y <<= min(lx, ly), 0;
			while (x.is2()) x.div2();
		} else {
			if (y -= x) return x <<= min(lx, ly), 0;
			while (y.is2()) y.div2();
		}
	}
	return 0;
}

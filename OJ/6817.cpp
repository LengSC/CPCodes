#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, _##i = ed; i <= _##i; ++i)
#define per(i, st, ed) for (int i = st, _##i = ed; i >= _##i; --i)

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
    ll n, m, p, cnt, b[20], md[20];

    ll fpow(ll a, ll b, ll p) {
        ll res = 1;
        for (; b; b >>= 1, (a *= a) %= p) if (b & 1) (res *= a) %= p;
        return res;
    }

    void exgcd(ll a, ll b, ll &x, ll &y) {
        if (!b) return x = 1, y = 0, void();
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }

    ll inv(ll a, ll p) {
        ll x, y;
        exgcd(a, p, x, y);
        return (x % p + p) % p;
    }

    ll crt(ll k, ll *b, ll *m) {
        ll M = 1, res = 0, Mi;
        rep(i, 1, k) M *= m[i];
        rep(i, 1, k) {
            Mi = M / m[i];
            (res += Mi * b[i] * inv(Mi, m[i])) %= M;
        }
        return (res % M + M) % M;
    }

    ll calc(ll n, ll p, ll pk) {
        /**
         * @arg p is a prime, pk = p^k
         * @return n! / pk (mod pk)
         */
        if (!n) return 1;
        ll res = 1;
        rep(i, 1, pk) if (i % p) (res *= i) %= pk;
        res = fpow(res, n / pk, pk);
        rep(i, 1, n % pk) if (i % p) (res *= i) %= pk;
        return res * calc(n / p, p, pk) % pk;
    }

    ll c(ll n, ll m, ll p, ll pk) {
        if (!m || n == m) return 1;
        if (n < m) return 0;
        ll fn = calc(n, p, pk), fm = calc(m, p, pk), fnm = calc(n - m, p, pk), e = 0, d = n - m;
        while (n) n /= p, e += n;
        while (m) m /= p, e -= m;
        while (d) d /= p, e -= d;
        return fn * inv(fm, pk) % pk * inv(fnm, pk) % pk * fpow(p, e, pk) % pk;
    }

    ll exlucas(ll n, ll m, ll p) {
        ll tmp = sqrt(p);
        for (ll i = 2, pk; i <= tmp && p >= 1; ++i) {
            pk = 1;
            while (!(p % i)) p /= i, pk *= i;
            if (pk > 1) b[++cnt] = c(n, m, i, pk), md[cnt] = pk;
        }
        if (p > 1) b[++cnt] = c(n, m, p, p), md[cnt] = p;
        return crt(cnt, b, md);
    }

    int main() {
        read(n, m, p);
        printf("%lld\n", exlucas(n, m, p));
        return 0;
    }
}

int main() { return SLV::main(); }
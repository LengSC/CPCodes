#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
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
    } using namespace IO;

    constexpr int N = 20;

    ll ans, T, p, n, n1, n2, s, a1[N], a2, f[N], b[N], md[N], facnt;

    ll fpow(ll a, ll b, ll p) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % p) if (b & 1) res = res * a % p;
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

    ll fac(ll n, ll p, ll pk, ll id) {
        if (!n) return 1;
        ll res = fpow(f[id], n / pk, pk);
        rep(i, 1, n % pk) if (i % p) res = res * i % pk;
        return res * fac(n / p, p, pk, id) % pk;
    }

    ll comb(ll n, ll m, ll p, ll pk, ll id) {
        if (n < m) return 0;
        if (!m || n == m) return 1;
        ll e = 0, d = n - m, res = fac(n, p, pk, id) * inv(fac(m, p, pk, id), pk) % pk * inv(fac(n - m, p, pk, id), pk) % pk;
        while (n) n /= p, e += n;
        while (m) m /= p, e -= m;
        while (d) d /= p, e -= d;
        return res * fpow(p, e, pk) % pk;
    }

    ll crt(ll k, ll *b, ll *m) {
        ll M = 1, res = 0, Mi;
        rep(i, 1, k) M *= m[i];
        rep(i, 1, k) Mi = M / m[i], res = (res + Mi * b[i] * inv(Mi, m[i])) % M;
        return (res % M + M) % M;
    }

    ll exlucas(ll n, ll m, ll p) {
        if (n < m) return 0;
        ll cnt = 0, pk, id = 0;
        for (ll i = 2; i * i <= p && p > 1; ++i) {
            pk = 1;
            while (!(p % i)) p /= i, pk *= i;
            if (pk > 1) b[++cnt] = comb(n, m, i, pk, ++id), md[cnt] = pk;
        }
        if (p > 1) b[++cnt] = comb(n, m, p, p, ++id), md[cnt] = p;
        return crt(cnt, b, md);
    }

    void pre(ll p) {
        ll pk;
        for (ll i = 2; p > 1; ++i) {
            pk = 1;
            if (p % i) continue;
            while (!(p % i)) p /= i, pk *= i;
            f[++facnt] = 1;
            rep(j, 1, pk) if (j % i) f[facnt] = f[facnt] * j % pk;
        }
    }

    void solve() {
        read(n, n1, n2, s);
        rep(i, 1, n1) read(a1[i]);
        rep(i, 1, n2) read(a2), s -= a2 - 1;
        ans = 0;
        rep(i, 0, (1 << n1) - 1) {
            ll sum = s;
            rep(j, 1, n1)
                if ((i >> (j - 1)) & 1) sum -= a1[j];
            ans = (ans + (__builtin_popcount(i) & 1 ? -1 : 1) * exlucas(sum - 1, n - 1, p)) % p;
        }
        printf("%lld\n", (ans + p) % p);
    }

    int main() {
        read(T, p);
        pre(p);
        for (; T; --T) solve();
        return 0;
    }
}

int main() { return SLV::main(); }

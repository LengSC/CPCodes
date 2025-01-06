#include <bits/stdc++.h>

namespace SLV {
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
    } using namespace IO;

    ll n, k, lim, ans, pre = -1, fac[50];
    vector<ll> res;

    ll get(ll x) {
        ll t = res[x];
        res.erase(res.begin() + x);
        return t;
    }

    bool check(ll x) {
        for (; x; x /= 10) {
            if (x % 10 != 4 && x % 10 != 7) return false;
        }
        return true;
    }

    void dfs(ll x) {
        if (x > lim) return;
        if (x != 0) ++ans;
        dfs(x * 10 + 4);
        dfs(x * 10 + 7);
    }

    int main() {
        read(n, k); --k;
        fac[0] = 1;
        rep(i, 1, n) {
            fac[i] = fac[i - 1] * i;
            res.emplace_back(n - i + 1);
            if (fac[i] > k) {
                pre = i;
                break;
            }
        }
        if (pre == -1) return puts("-1"), 0;
        // sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        lim = n - pre;
        dfs(0);
        per(i, pre, 1) {
            ll num = get(k / fac[i - 1]), pos = n - i + 1;
            if (check(pos) && check(num)) ++ans;
            k = k % fac[i - 1];
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }
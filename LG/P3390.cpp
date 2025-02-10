#include <bits/stdc++.h>

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
    #define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    using uint = unsigned int;
    using ll = long long;
    using ull = unsigned long long;
    using vi = vector<int>;
    using pii = pair<int, int>;
    namespace IO { template<typename T> void read(T &x) { x = 0; char c = getchar(); bool f = false; while (!isdigit(c)) f = (c == '-'), c = getchar(); while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); if (f) x = -x; } template<typename T, typename ...Nxt> void read(T &x, Nxt &...nxt) { read(x), read(nxt...); } } using namespace IO;

    constexpr int N = 102, MOD = 1e9 + 7;

    ll n, k;

    struct Mat {
        ll a[N][N];

        Mat() { memset(a, 0, sizeof(a)); }

        void init() { rep(i, 1, n) a[i][i] = 1; }

        friend Mat operator*(const Mat &a, const Mat &b) {
            Mat res; int r;
            rep(i, 1, n) rep(k, 1, n) {
                r = a.a[i][k];
                rep(j, 1, n) (res.a[i][j] += b.a[k][j] * r) %= MOD;
            }
            return res;
        }

        friend Mat operator^(Mat a, ll b) {
            Mat res; res.init();
            for (; b; b >>= 1, a = a * a) if (b & 1) res = res * a;
            return res;
        }
    } mat, ans;

    int main() {
        read(n, k);
        rep(i, 1, n) rep(j, 1, n) read(mat.a[i][j]);
        ans = mat ^ k;
        rep(i, 1, n) rep(j, 1, n) printf("%lld%c", ans.a[i][j], " \n"[j == n]);
        return 0;
    }
}

int main() { return SLV::main(); }

#include <bits/stdc++.h>

#define R register
#define eps 1e-12
#define INF (1<<30)
#define LL long long
#define LINF (1ll<<60)
#define MM(x, y) memset(x, y, sizeof x)
#define Fo(i, x, y) for(R int i=x; i<=y; ++i)
#define Ro(i, x, y) for(R int i=x; i>=y; --i)
using namespace std;
template<typename T> inline T Max(R T x, R T y) {return x > y ? x : y;}
template<typename T> inline T Min(R T x, R T y) {return x < y ? x : y;}
template<typename T> inline void in(R T &x)
{
    static int ch; static bool flag;
    for(flag=false, ch=getchar(); ch<'0'||ch>'9'; ch=getchar()) flag |= ch=='-';
    for(x=0; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1) + (x<<3) + ch - '0';
    x = flag ? -x : x;
}
#define MD 100000000
#define Big BigInt

namespace SLV {
    #define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
    #define dep(i, st, ed) for (int i = (st), _##i = (ed); i < _##i; ++i)
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

    constexpr int N = 202;

    namespace BIGINT {
        constexpr int BASE = 1e8;

        struct BigInt {
            ll a[N];

            BigInt() = default;

            BigInt(ll x) {
                memset(a, 0, sizeof(a));
                while (x) a[++a[0]] = x % BASE, x /= BASE;
            }

            void clear() { memset(a, 0, sizeof(a)); }

            void print() {
                printf("%lld", a[a[0]]);
                per(i, a[0] - 1, 1) printf("%08lld", a[i]);
                puts("");
            }

            friend BigInt operator+(const BigInt &lhs, const BigInt &rhs) { //ERR!!!
                BigInt res; res.clear();
                res.a[0] = max(lhs.a[0], rhs.a[0]);
                rep(i, 1, res.a[0]) res.a[i] = lhs.a[i] + rhs.a[i];
                rep(i, 1, res.a[0]-1) res.a[i + 1] += res.a[i] / BASE, res.a[i] %= BASE;
                while (res.a[res.a[0]] >= BASE) res.a[res.a[0] + 1] = res.a[res.a[0]] / BASE, res.a[res.a[0]] %= BASE, ++res.a[0];
                return res;
            }

            friend BigInt operator-(const BigInt &lhs, const BigInt &rhs) {
                BigInt res; res.clear();
                res.a[0] = lhs.a[0];
                rep(i, 1, res.a[0]) {
                    res.a[i] += lhs.a[i] - rhs.a[i];
                    if (res.a[i] < 0) res.a[i] += BASE, --res.a[i + 1];
                }
                while (!res.a[res.a[0]] && res.a[0]) --res.a[0];
                return res;
            }

            friend BigInt operator*(const BigInt &lhs, const ll &rhs) {
                BigInt res; res.clear();
                res.a[0] = lhs.a[0];
                rep(i, 1, lhs.a[0]) res.a[i] += lhs.a[i] * rhs, res.a[i + 1] = res.a[i] / BASE, res.a[i] %= BASE;
                while (res.a[res.a[0] + 1]) ++res.a[0], res.a[res.a[0] + 1] = res.a[res.a[0]] / BASE, res.a[res.a[0]] %= BASE;
                return res;
            }

            friend BigInt operator*(const BigInt &lhs, const BigInt &rhs) {
                BigInt res; res.clear();
                res.a[0] = max(lhs.a[0] + rhs.a[0] - 1, 0ll);
                rep(i, 1, lhs.a[0]) rep(j, 1, rhs.a[0]) {
                    res.a[i + j - 1] += lhs.a[i] * rhs.a[j];
                    res.a[i + j] += res.a[i + j - 1] / BASE;
                    res.a[i + j - 1] %= BASE;
                }
                while (res.a[res.a[0] + 1]) ++res.a[0], res.a[res.a[0] + 1] = res.a[res.a[0]] / BASE, res.a[res.a[0]] %= BASE;
                return res;
            }
        };
    } using BIGINT::BigInt;

    BigInt f[2][N], comb[N][N], fac[N], ans;
    ll n, k, hm[N], hf[N];

    int main() {
        read(n, k);
        rep(i, 1, n) read(hm[i]); rep(i, 1, n) read(hf[i]);
        sort(hm + 1, hm + 1 + n), sort(hf + 1, hf + 1 + n);
        f[0][0] = comb[0][0] = fac[0] = {1ll};
        for (int i = 1, cnt = 0; i <= n; ++i) {
            while (hf[i] > hm[cnt + 1] && cnt + 1 <= n) ++cnt;
            rep(j, 0, i) {
                f[i&1][j] = f[!(i&1)][j];
                if (cnt - (j - 1) > 0) f[i&1][j] = f[i&1][j] + f[!(i&1)][j - 1] * (cnt - (j - 1));
            }
        }
        rep(i, 1, n) fac[i] = fac[i - 1] * i;
        rep(i, 0, n) comb[i][0] = {1};
        rep(i, 1, n) rep(j, 1, i) comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        rep(i, 0, n) f[n&1][i] = f[n&1][i] * fac[n - i];
        per(i, n, 0) rep(j, i + 1, n) f[n&1][i] = f[n&1][i] - comb[j][i] * f[n&1][j];
        rep(i, 0, k) ans = ans + f[n&1][i];
        ans.print();
        return 0;
    }
}

int main() { return SLV::main(); }

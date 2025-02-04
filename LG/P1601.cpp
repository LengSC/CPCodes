#include <bits/stdc++.h>

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
            
            BigInt(char *s) {
                memset(a, 0, sizeof(a));
                int sl = strlen(s), p = sl - 1;
                a[0] = sl / 8 + (sl % 8 ? 1 : 0);
                rep(i, 1, a[0]) {
                    per(j, min(p, 7), 0) a[i] = a[i] * 10 + (s[p - j] - '0');
                    p -= 8;
                }
            }

            void clear() { memset(a, 0, sizeof(a)); }

            void print() {
                printf("%lld", a[a[0]]);
                per(i, a[0] - 1, 1) printf("%08lld", a[i]);
                puts("");
            }

            friend BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
                BigInt res; res.clear();
                res.a[0] = max(lhs.a[0], rhs.a[0]);
                rep(i, 1, res.a[0]) res.a[i] = lhs.a[i] + rhs.a[i];
                rep(i, 1, res.a[0]) res.a[i + 1] += res.a[i] / BASE, res.a[i] %= BASE;
                while (res.a[res.a[0] + 1]) res.a[res.a[0] + 1] = res.a[res.a[0]] / BASE, res.a[res.a[0]] %= BASE, ++res.a[0];
                return res;
            }
        };
    } using BIGINT::BigInt;

    char sa[505], sb[505];

    int main() {
        scanf("%s %s", sa, sb);
        BigInt a(sa), b(sb);
        (a + b).print();
        return 0;
    }
}

int main() { return SLV::main(); }

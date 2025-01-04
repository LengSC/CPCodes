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
    int n, p, f[2][4202], ans;

    int main() {
        read(n, p);
        f[0][2] = 1;
        rep(i, 3, n)
            rep(j, 2, i)
                f[i & 1][j] = (f[i & 1][j - 1] + f[i & 1 ^ 1][i + 1 - j]) % p;
        rep(i, 2, n) (ans += f[n & 1][i]) %= p;
        printf("%d\n", ans * 2 % p);
        return 0;
    }
}

int main() { return SLV::main(); }

/* BF + OEIS.org
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
    constexpr int N = 4202;

    int n, p;
    ll ans; int a[N];
    bool vis[N];

    void dfs(int cur) {
        if (cur == n + 1) {
            ++ans;
            cerr << ans << " ";
            rep(i, 1, n) cerr << a[i] << " ";
            cerr << endl;
            return;
        }
        if (cur > 2) {
            if (a[cur - 2] > a[cur - 1]) {
                rep(i, a[cur - 1] + 1, n) {
                    if (vis[i]) continue;
                    vis[i] = true;
                    a[cur] = i;
                    dfs(cur + 1);
                    vis[i] = false;
                }
            } else {
                per(i, a[cur - 1] - 1, 1) {
                    if (vis[i]) continue;
                    vis[i] = true;
                    a[cur] = i;
                    dfs(cur + 1);
                    vis[i] = false;
                }
            }
        } else {
            rep(i, 1, n) {
                if (vis[i]) continue;
                vis[i] = true;
                a[cur] = i;
                dfs(cur + 1);
                vis[i] = false;
            }
        }
    }

    int main() {
        read(n, p);
        rep(i, 1, n) {
            a[1] = i;
            vis[i] = true;
            dfs(2);
            vis[i] = false;
        }
        printf("%lld\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }
*/
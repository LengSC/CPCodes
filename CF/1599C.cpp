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

    int n, ans;
    double p, sum;

    bool check(int x) {
        sum = 0;
        if (x >= 1 && x <= n - 2) sum += 3 * x * (n - x) * (n - x - 1) / 2;
        if (x >= 2 && x <= n - 1) sum += 3 * x * (x - 1) * (n - x);
        if (x >= 3) sum += x * (x - 1) * (x - 2);
        return (sum / (double)(n * (n - 1) * (n - 2))) >= p;
    }

    int main() {
        scanf("%d %lf", &n, &p);
        for (int l = 0, r = n, mid; l <= r;) {
            mid = (l + r) / 2;
            if (check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", ans);
        return 0;
    }
}

int main() { return SLV::main(); }

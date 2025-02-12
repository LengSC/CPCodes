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

    constexpr int N = 1e5;

    ll n, m, phi[N + 2], p, l, r, x, y, sum;
    bitset<N + 2> np;
    vi pr;

    void pre() {
        phi[1] = 1;
        rep(i, 2, N) {
            if (!np[i]) pr.eb(i), phi[i] = i - 1;
            for (const auto &j: pr) {
                if ((p = i * j) > N) break;
                np[p] = true;
                if (i % j) phi[p] = phi[i] * phi[j];
                else { phi[p] = phi[i] * j; break; }
            }
        }
        rep(i, 2, N) phi[i] += phi[i - 1];
    }

    int main() {
        pre();
        read(n, m);
        if (n > m) swap(n, m);
        for (l = 1; l <= n; l = r + 1)
            r = min(n / (x = n / l), m / (y = m / l)),
            sum += (phi[r] - phi[l - 1]) * x * y;
        printf("%lld\n", sum * 2 - n * m);
        return 0;
    }
}

int main() { return SLV::main(); }

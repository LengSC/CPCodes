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

    constexpr int N = 4e4 + 2;

    struct Bg {
        int l, r, h;
    } bgs[N];

    int n;

    namespace ODT {
        struct Node {
            int l, r;
            mutable int v;
            Node(int l, int r, int v): l(l), r(r), v(v) {}
            bool operator< (const Node &b) const { return l < b.l; }
        };

        struct {
            set<Node> tr;

            auto split(int x) {
                // if (x > bgs[n].r + 1) return tr.end();
                auto it = --tr.upper_bound({x, 0, 0});
                if (it->l == x) return it;
                int l = it->l, r = it->r, v = it->v;
                tr.erase(it);
                tr.emplace(l, x - 1, v);
                return tr.emplace(x, r, v).first;
                // auto it = tr.lower_bound({x, 0, 0});
                // if (it != tr.end() && it->l == x) return it;
                // --it;
                // int l = it->l, r = it->r, v = it->v;
                // tr.erase(it);
                // tr.emplace(l, x - 1, v);
                // return tr.emplace(x, r, v).first;
            }

            void assign(int l, int r, int v) {
                auto itr(split(r + 1)), itl(split(l));
                tr.erase(itl, itr);
                tr.emplace(l, r, v);
            }

            ll area() {
                ll res = 0;
                for (auto it = tr.begin(); it != tr.end(); ++it) {
                    res += (ll)(it->r - it->l + 1) * it->v;
                    cerr << it->l << " " << it->r << " " << it->v << endl;
                }
                return res;
            }
        } odt;
    } using ODT::odt;

    int main() {
        read(n);
        rep(i, 1, n) read(bgs[i].l, bgs[i].r, bgs[i].h), --bgs[i].r;
        sort(bgs + 1, bgs + 1 + n, [](const Bg &a, const Bg &b) {
            return a.h < b.h;
        });
        // odt.tr.emplace(0, bgs[n].r + 1, 0);
        odt.tr.emplace(1, bgs[n].r, 0);
        odt.tr.emplace(bgs[n].r + 1, bgs[n].r + 1, 0);
        rep(i, 1, n) odt.assign(bgs[i].l, bgs[i].r, bgs[i].h);
        printf("%lld\n", odt.area());
        return 0;
    }
}

int main() { return SLV::main(); }
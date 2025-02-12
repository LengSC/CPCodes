#include <bits/stdc++.h>
#define rep(i, st, ed) for (int i = st, e##i = ed; i <= e##i; ++i)
#define per(i, st, ed) for (int i = st, e##i = ed; i >= e##i; --i)

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

int n, m, bl, br;

namespace ODT {
    struct Node {
        int l, r;
        mutable int v;
        Node(int l, int r, int v) : l(l), r(r), v(v) {}
        bool operator <(const Node &b) const { return l < b.l; }
    };
    
    struct {
        set<Node> tr;

        void init(int l, int r, int v) { tr.emplace(l - 1, r + 1, v); }

        auto split(int x) {
            if (x > n) return tr.end();
            auto it = --tr.upper_bound({x, 0, 0});
            if (it->l == x) return it;
            int l = it->l, r = it->r, v = it->v;
            tr.erase(it);
            tr.emplace(l, x - 1, v);
            return tr.emplace(x, r, v).first;
        }

        void assign(int l, int r, int v) {
            auto itr = split(r + 1), itl = split(l);
            tr.erase(itl, itr);
            tr.emplace(l, r, v);
        }

        int count() {
            auto itr = split(n + 1), itl = split(1);
            set<int> clrs;
            for (; itl != itr; ++itl) if (itl->v) clrs.emplace(itl->v);
            return clrs.size();
        }
    } odt;
}
using namespace ODT;

namespace SLV {
    int main() {
        read(n, m);
        odt.init(1, n, 0);
        rep(i, 1, m) {
            read(bl, br);
            odt.assign(bl, br, i);
        }
        printf("%d\n", odt.count());
        return 0;
    }
}

int main() { return SLV::main(); }
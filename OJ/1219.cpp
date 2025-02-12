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

    int n, t, m, a, b, c;
    char op;

    namespace ODT {
        struct Node {
            int l, r;
            mutable int v;
            Node(int l, int r, int v): l(l), r(r), v(v) {}
            bool operator<(const Node &b) const { return l < b.l; }
        };
        set<Node> tr;

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

        int count(int l, int r) {
            auto itr = split(r + 1), itl = split(l);
            set<int> clrs;
            for (; itl != itr; ++itl) clrs.emplace(itl->v);
            return clrs.size();
        }
    }

    int main() {
        read(n, t, m);
        ODT::tr.emplace(0, n + 1, 1);
        rep(i, 1, m) {
            scanf("%c", &op), read(a, b);
            if (op == 'C') {
                read(c);
                ODT::assign(a, b, c);
            } else {
                printf("%d\n", ODT::count(a, b));
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }

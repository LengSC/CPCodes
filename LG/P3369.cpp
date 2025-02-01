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

    namespace TREAP {
        struct Node {
            Node *ls, *rs;
            int val, prio, cnt, siz;

            Node(int _v): val(_v), prio(rand()), cnt(1), siz(1), ls(nullptr), rs(nullptr) {}

            Node(Node *_n): val(_n->val), prio(_n->prio), cnt(_n->cnt), siz(_n->siz) {}

            void updSiz() {
                siz = cnt;
                if (ls != nullptr) siz += ls->siz;
                if (rs != nullptr) siz += rs->siz;
            }
        };

        struct Treap {
            Node *root;

            pair<Node *, Node *> splitByVal(Node *cur, int key) {
                if (cur == nullptr) return {nullptr, nullptr};
                if (cur->val <= key) {
                    auto tmp = splitByVal(cur->rs, key);
                    cur->rs = tmp.first;
                    cur->updSiz();
                    return {cur, tmp.second};
                } else {
                    auto tmp = splitByVal(cur->ls, key);
                    cur->ls = tmp.second;
                    cur->updSiz();
                    return {tmp.first, cur};
                }
            }

            tuple<Node *, Node *, Node *> splitByRnk(Node *cur, int rnk) {
                if (cur == nullptr) return {nullptr, nullptr, nullptr};
                int lsiz = cur->ls == nullptr ? 0 : cur->ls->siz;
                if (rnk <= lsiz) {
                    Node *l, *mid, *r;
                    tie(l, mid, r) = splitByRnk(cur->ls, rnk);
                    cur->ls = r;
                    cur->updSiz();
                    return {l, mid, cur};
                } else if (rnk <= lsiz + cur->cnt) {
                    Node *l = cur->ls, *r = cur->rs;
                    cur->ls = cur->rs = nullptr;
                    return {l, cur, r};
                } else {
                    Node *l, *mid, *r;
                    tie(l, mid, r) = splitByRnk(cur->rs, rnk - lsiz - cur->cnt);
                    cur->rs = l;
                    cur->updSiz();
                    return {cur, mid, r};
                }
            }

            Node *merge(Node *u, Node *v) {
                if (u == nullptr && v == nullptr) return nullptr;
                if (u != nullptr && v == nullptr) return u;
                if (u == nullptr && v != nullptr) return v;
                if (u->prio < v->prio) {
                    u->rs = merge(u->rs, v);
                    u->updSiz();
                    return u;
                } else {
                    v->ls = merge(u, v->ls);
                    v->updSiz();
                    return v;
                }
            }

            void insert(int val) {
                auto tmp = splitByVal(root, val);
                auto l = splitByVal(tmp.first, val - 1);
                Node *node;
                if (l.second == nullptr)
                    node = new Node(val);
                else {
                    ++(l.second->cnt);
                    l.second->updSiz();
                }
                Node *lc = merge(l.first, l.second == nullptr ? node : l.second);
                root = merge(lc, tmp.second);
            }

            void del(int val) {
                auto tmp = splitByVal(root, val);
                auto l = splitByVal(tmp.first, val - 1);
                if (l.second->cnt > 1) {
                    --(l.second->cnt);
                    l.second->updSiz();
                    l.first = merge(l.first, l.second);
                } else {
                    if (tmp.first == l.second)
                        tmp.first = nullptr;
                    delete l.second;
                    l.second = nullptr;
                }
                root = merge(l.first, tmp.second);
            }

            int qRnkByVal(Node *cur, int val) {
                auto tmp = splitByVal(cur, val - 1);
                int res = (tmp.first == nullptr ? 0 : tmp.first->siz) + 1;
                root = merge(tmp.first, tmp.second);
                return res;
            }

            int qValByRnk(Node *cur, int rnk) {
                Node *l, *mid, *r;
                tie(l, mid, r) = splitByRnk(cur, rnk);
                int res = mid->val;
                root = merge(merge(l, mid), r);
                return res;
            }

            int qPrev(int val) {
                auto tmp = splitByVal(root, val - 1);
                int res = qValByRnk(tmp.first, tmp.first->siz);
                root = merge(tmp.first, tmp.second);
                return res;
            }

            int qNext(int val) {
                auto tmp = splitByVal(root, val);
                int res = qValByRnk(tmp.second, 1);
                root = merge(tmp.first, tmp.second);
                return res;
            }
        };
    }

    TREAP::Treap tr;
    int q, op, arg;

    int main() {
        srand(time(nullptr));
        for (read(q); q; --q) {
            read(op, arg);
            switch (op) {
                case 1: tr.insert(arg); break;
                case 2: tr.del(arg); break;
                case 3: printf("%d\n", tr.qRnkByVal(tr.root, arg)); break;
                case 4: printf("%d\n", tr.qValByRnk(tr.root, arg)); break;
                case 5: printf("%d\n", tr.qPrev(arg)); break;
                case 6: printf("%d\n", tr.qNext(arg)); break;
            }
        }
        return 0;
    }
}

int main() { return SLV::main(); }

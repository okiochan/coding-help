struct node {
    int minv, maxv;
    node() { minv = INF; maxv = 0;}
    node(int minv, int maxv) : minv(minv), maxv(maxv) {}
    node(const node& a, const node&b) {
        maxv = max(a.maxv, b.maxv);
        minv = min(a.minv, b.minv);
    }
};

struct seg_tree {
    int ds;
    vector <node> tree;

    seg_tree(int n) {
        for (ds=1;ds<n;ds*=2);
        tree.assign(2*ds+1, node()); 
    }

    void build(vec &a) { build(1, 0, ds - 1, a); }
    void build(int v, int tl, int tr, vec &a) {
        if (tl == tr) {
            if(tl < sz(a)) {
                tree[v].minv = a[tl];
                tree[v].maxv = a[tl];
            }
            return;
        }

        int m = (tl + tr) / 2;
        build(v * 2, tl, m, a);
        build(v * 2 + 1, m + 1, tr, a);

        tree[v] = node(tree[v + v], tree[v + v + 1]);
    }

    node get(int l, int r) { return get(1, 0, ds - 1, l, r); }
    node get(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r) return node();

        if (l <= tl && tr <= r) {
            return tree[v];
        }

        int mid = (tl + tr) / 2;
        return node(get(v * 2, tl, mid, l, r), get(v * 2 + 1, mid + 1, tr, l, r));
    }

    void update(int pos, node noda) { update(1, 0, ds - 1, pos, noda); }
    void update(int v, int tl, int tr, int pos, node noda) {
        if (tl == tr) {
            tree[v] = noda;
            return;
        }

        int m = (tl + tr) / 2;
        if (pos <= m) {
            update(v * 2, tl, m, pos, noda);
        } else {
            update(v * 2 + 1, m + 1, tr, pos, noda);
        }

        tree[v] = node(tree[v + v], tree[v + v + 1]);
    }
};
struct node {
    int val, add_val;
    node() { val = 0; add_val = 0; }
};

struct seg_tree_op {
    vector <node> tree;
    int n;

    seg_tree_op(int n) : n(n) { tree.resize(4 * n); }

    void build(int *a) { build(1, 0, n - 1, a); };
    void build(int v, int tl, int tr, int *a) {
        if (tl == tr) {
            tree[v].val = a[tl];
            return;
        }

        int m = (tl + tr) / 2;
        build(v * 2, tl, m, a);
        build(v * 2 + 1, m + 1, tr, a);

        tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
    }

    void push(int v, int tl, int tr) {
        //update child; int v - always true
        if (tl != tr)  {
            tree[v * 2].val += tree[v].add_val;
            tree[v * 2].add_val += tree[v].add_val;

            tree[v * 2 + 1].val += tree[v].add_val;
            tree[v * 2 + 1].add_val += tree[v].add_val;
        }
        tree[v].add_val = 0;
    }

    void update_lr(int l, int r, int val) { update_lr(1, 0, n - 1, l, r, val); }
    void update_lr(int v, int tl, int tr, int l, int r, int val) {
        if (l > r || tr < l || tl > r) return;

        if (l <= tl && r <= tr) {
            tree[v].val = val;
            tree[v].add_val += val;
        } else {
            push(v, tl, tr);

            int m = (tl + tr) / 2;
            update_lr(v * 2, 0, m, l, r, val);
            update_lr(v * 2 + 1, m + 1, tr, l, r, val);

            tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
        }
    }

    int get_val(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return tree[v].val;
        } else {
            push(v, tl, tr);
            int m = (tl + tr) / 2;
            if (pos <= m) {
                return get_val(v * 2, 0, m, pos);
            } else {
                return get_val(v * 2 + 1, m + 1, tr, pos);
            }
        }
    }

};
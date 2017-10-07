
struct seg_tree
{
	struct node
	{
		int val;
	};

	int n;
	vector <node> tree;

	seg_tree(int n) :n(n) { tree.resize(4 * n + 10); }

	void build(int *a) { build(1, 0, n - 1, a); }
	void build(int v, int tl, int tr, int *a)
	{
		if (tl == tr)
		{
			tree[v].val = a[tl];
			return;
		}

		int m = (tl + tr) / 2;
		build(v * 2, tl, m, a);
		build(v * 2 + 1, m + 1, tr, a);

		tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
	}

	int sum(int l, int r){ sum(1, 0, n - 1, l, r); }
	int sum(int v, int tl, int tr, int l, int r)
	{
		if (l > r) return 0;

		if (l == tl && r == tr)
			return tree[v].val;

		int mid = (tl + tr) / 2;
		return sum(v * 2, tl, mid, l, min(r, mid))
			+ sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
	}

	void update(int pos, int val){ update(1, 0, n - 1, pos, val); }
	void update(int v, int tl, int tr, int pos, int val)
	{
		if (tl == tr)
		{
			tree[v].val = val;
			return;
		}

		int m = (tl + tr) / 2;

		if (pos <= m) //l
		{
			update(v * 2, tl, m, pos, val);
		} else // r
		{
			update(v * 2 + 1, m + 1, tr, pos, val);
		}

		tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
	}

};
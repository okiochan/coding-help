
struct treap;
void update(treap *t);

struct treap
{
	int L, R, sz, y;
	treap(int L, int R, int y = rand(), treap *l = 0, treap *r = 0) : L(L), R(R), y(y), l(l), r(r) { update(this); };
	treap *l, *r;
};

void update(treap *t)
{
	if (t == 0)return;

	t->sz = t->R - t->L + 1;
	if (t->l != 0) t->sz += t->l->sz;
	if (t->r != 0) t->sz += t->r->sz;
}

treap *merge(treap *l, treap *r)
{
	if (l == 0) return r;
	if (r == 0) return l;

	if (l->y < r->y)
	{
		r->l = merge(l, r->l);
		update(r);
		return r;
	} else
	{
		l->r = merge(l->r, r);
		update(l);
		return l;
	}
}
void dump(treap *t) {
	if (!t)return;
	dump(t->l);
	printf("[%d %d] ", t->L, t->R);
	dump(t->r);
}

void split(treap *t, int x, int add, treap *&l, treap *&m, treap *&r)
{
	int Lsz = (t->l == 0 ? 0 : t->l->sz);
	int Lx = Lsz + 1 + add;
	int Rx = Lx + t->R - t->L;
	int Sz = t->R - t->L + 1;

	treap *L, *R;

	if (x < Lx)
	{
		split(t->l, x, add, L, m, R);
		t->l = R;
		l = L; r = t;

	} else if (x > Rx)
	{
		split(t->r, x, Lsz + add + Sz, L, m, R);
		t->r = L;
		l = t; r = R;

	} else
	{
		int xp = x - Lx + t->L;

		treap *L, *R;

		if (xp - 1 < t->L) {
			L = t->l;
		} else {
			L = new treap(t->L, xp - 1);
			L->l = t->l;
		}


		treap *M = new treap(xp, xp);

		if (t->R < xp + 1) {
			R = t->r;
		} else {
			R = new treap(xp + 1, t->R);
			R->r = t->r;
		}



		l = L; r = R; m = M;
		update(l); update(m); update(r);
	}

	update(t);
	return;
}


int main(ll argc, char * argv[])
{
#ifdef Home
	freopen("inp.txt", "rb", stdin);
#endif 
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;
	treap *t = new treap(1, (int)(1e9 + 2e5));

	while (m--)
	{
		char c; cin >> c;
		int x; cin >> x;
		/*dump(t);
		cout << endl;*/

		if (c == 'L')
		{
			treap *l, *m, *r;
			split(t, x, 0, l, m, r);

			cout << m->L << endl;
			t = merge(merge(l, m), r);
		} else
		{
			treap *l, *m, *r;
			split(t, x, 0, l, m, r);

			t = merge(l, r);
		}
	}



	return 0;
}










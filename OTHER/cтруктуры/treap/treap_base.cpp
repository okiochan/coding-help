
struct treap
{
	int x,y;
	treap(int x=0, int y=rand(), treap *l=0, treap *r=0) : x(x), y(y), l(l), r(r) {};
	treap *l,*r;
};

treap *merge(treap *l, treap *r)
{
	if(l==0) return r;
	if(r==0) return l;

	if( l->y < r->y )
	{
		r -> l = merge(l, r->l);
		return r;
	}
	else
	{
		l -> r = merge(l->r,r);
		return l;
	}
}

void split(treap *t, int x, treap *&l, treap *&r)
{
	if (t == 0)
	{
        l = r = 0;
    }
	else
	{
		treap *L,*R;

		if(x >= t->x )
		{
			split(t->r,x,L,R);
			t->r = L;
			l=t; r=R;
		}
		else
		{
			split(t->l,x,L,R);
			t->l = R;
			l = L; r = t;
		}
	}
	return;
}

void print(treap *t)
{
	if(t==0) return;

	print(t->l);
		cout << t->x << " ";
	print(t->r);
	return;
}


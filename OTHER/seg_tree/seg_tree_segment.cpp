int a[N];
vector <int> t[4*N];
 
void build (int v, int tl, int tr)
{
	if (tl == tr) //leaf
	{
		t[v] = vector<int> (1, a[tl]);
		return;
	}
	
	int tm = (tl + tr) / 2;
	build (v*2, tl, tm);
	build (v*2+1, tm+1, tr);

	merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),back_inserter (t[v]));	
}
	
int query (int v, int tl, int tr, int l, int r, int x)
{
	if (l > r) return INF;

	if (l == tl && tr == r)
	{
		vector<int>::iterator pos = lower_bound (t[v].begin(), t[v].end(), x);

		if (pos != t[v].end()) return *pos;
		return INF;
	}

	int tm = (tl + tr) / 2;
	return min (
				query (v*2, tl, tm, l, min(r,tm), x),
				query (v*2+1, tm+1, tr, max(l,tm+1), r, x)
			   );
}


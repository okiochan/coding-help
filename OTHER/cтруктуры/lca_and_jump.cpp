
int up[N][L], tin[N], tout[N], len[N];
int timer, l;

void dfs(int v, int p)
{
	tin[v] = timer++;
	up[v][0] = p;

	len[v] = len[p] + 1;

	for(int i=1; i<=l; i++)
	{
		int pr = up[v][i-1];
		up[v][i] = up[pr][i-1];
	}

	for(int i=0; i<g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
			dfs(to,v);
	}

	tout[v] = timer++;
}

//a -> b
bool upper(int a, int b)
{
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b)
{
	if( upper(a,b)) return a;
	if( upper(b,a)) return b;

	for(int i=l; i >=0; i--)
	{
		if(upper( up[a][i], b)) continue;
		a = up[a][i];
	}

	return up[a][0];
}

int dist(int v1, int v2, int par)
{
	return (len[v1]-len[par] + len[v2]-len[par]);
}

int down_par_on_dist(int v, int par, int d)
{
	if(d == 0) return par;
	if(d == dist(v,par,par)) return v;

	for(int i=l; i >=0; i--)
	{
		int cur = up[v][i];	
		if(upper( cur, par) || dist(cur,par,par) < d) continue;
		v = cur;
	}

	if(dist(v,par,par) == d) return v;
	return 0;
}

void init(int n, int s)
{
	l=1;
	while((1<<l) <= n) l++;
	memset(len,-1,sizeof(len));
	dfs(s,s);
}










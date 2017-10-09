
void dfs_d(int v, int p, int d, int &res, int &maxd)
{
	if(d > maxd)
	{
		maxd=d; res = v;
	}

	for(int i=0; i<g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
			dfs_d(to,v,d+1,res,maxd);
	}
}

void get_d(int &v1, int &v2)
{
	int maxd = 0;
	dfs_d(v1,-1,0,v1,maxd);
	maxd=0;
	dfs_d(v1,-1,0,v2,maxd);
}








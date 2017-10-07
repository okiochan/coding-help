
vector <pair<int,int> > g[N]; 
multiset < pair<int,int> > q;
vector<int> d(N, INF); 

void init()
{
	int n, m,a,b, dist; cin >> n >> m;

	 for(int i=0; i<m; i++)
	 {
		 cin >> a >> b >> dist; 
		 g[a].push_back(make_pair (b, dist));
		 g[b].push_back(make_pair (a, dist));
	  }
}

void solve()
{
	int s = 0;	d[s] = 0;
 q.insert (make_pair (d[s], s));

	 while (!q.empty())
	 {
		int v = q.begin()->second;
		q.erase (q.begin());
 
		for (short i=0; i<g[v].size(); i++)
		{

			int to = g[v][i].first,
				len = g[v][i].second;

			if (d[v] + len < d[to])
			{
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
			
				q.insert (make_pair (d[to], to));
			}
		}
	}

}

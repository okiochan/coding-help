
int n,m;
bool used[N];

struct rib
{
    int from, to, cost, flow, back_pos;
};
vector<rib> g[N];
 
int S(){ return 1; }
int Left(int i){ return (2+i); }
int Right(int i){ return ( 2 + n + i); }
int T(){ return (n+m+2); }

void add_rib(int from, int to, int cost, int flow)
{
    rib e1 = { from, to,cost,flow,g[to].size() };
    rib e2 = { to,from,-cost,0,g[from].size() };
    g[from].push_back(e1);
    g[to].push_back(e2);
}

bool levit( vector <int> &path)
{
	vector<int> d (n, INF);
	d[S()] = 0;

	vector<int> id (n);
	deque<int> q;

	q.push_back (S());
	vector<int> p (n, -1);

	while (!q.empty())
	{
		int v = q.front();  q.pop_front();
		id[v] = 1;

		for (int i=0; i<g[v].size(); i++)
		{
			int to = g[v][i].to, len = g[v][i].cost;

			if ( (d[v] + len) < d[to])
			{
				d[to] = d[v] + len;

				if (id[to] == 0)
					q.push_back (to);
				else if (id[to] == 1)
					q.push_front (to);

				p[to] = v;
				id[to] = 1;
			}
		}
	}
    
	vector <int> path;
	int v = p[T()];
	if(v == -1) return false;

	while(v != -1)
	{
		path.push_back(v);
		v = p[v];
	}

	reverse(path.begin(), path.end());
	return true;
}

void findFlow( vector<int> &path, int &ans )
{
	int max_cap = 0;
	for(int i=0; i<(path.size()-1); i++)
		max_cap = max(max_cap, g[ path[i] ][ path[i+1] ].flow); 

	for(int i=0; i<(path.size()-1); i++)
	{
		int v = path[i];
		int to = path[i+1];
		
		ans += g[v][to].cost;
		g[v][to].flow -= max_cap;
		g[to][ g[v][to].back_pos ].flow += max_cap;
	}
}

int minCostMaxFlow()
{
	vector <int> path;
	int ans = 0;

	for(;;)
	{
		path.clear();

		if( levit(path))
			findFlow(path, ans);
		else
			break;
	}
}


int n,m, S,T;
bool used[N];

struct rib
{
    int from, to, cost, flow, back_pos;
};
vector<rib> g[N];
 
int Left(int i){ return (2+i); }
int Right(int i){ return ( 2 + n + i); }

void add_rib(int from, int to, int cost, int flow)
{
    rib e1 = { from, to,cost,flow,g[to].size() };
    rib e2 = { to,from,-cost,0,g[from].size() };
    g[from].push_back(e1);
    g[to].push_back(e2);
}

bool findFlow(int v)
{
	if(v == T)
		return true;

	used[v] = 1;
	for(int i=0; i<g[v].size(); i++)
	{
		int to = g[v][i].to;

		if( !used[to] && g[v][i].flow >= cap && findFlow(to)  )
		{
			g[v][i].flow -= cap;
			g[to][ g[v][i].back_pos ].flow += cap;
			return true;
		}
	}	
	return false;
}

int getMaxFlow()
{
	int ans = 0;
	while(cap > 0)
	{
		memset(used,0,sizeof(used));
		if(findFlow(S))
			ans += cap;
		else
			cap /= 2;
	}
	return ans;	
}

void init()
{
	cin >>n >> m;
	FOR(i,0,n)
	{
      FOR(j,0,m)
	  {
		  int a,b; cin >> a >> b; a--; b--;

		  add_rib(Left(a), Right(b), 0, 1);
	  }
	}
    
	S=1; T=n+m+2;

	FOR(i,0,n)
	{
		add_rib(S, Left(i), 0, 1);
	}
	FOR(i,0,m)
	{
		add_rib(Right(i), T, 0, 1);
	}
}

void printPath()
{
	FOR(i,0,n)
	{
		int to = Right(i);
		FOR(j,0,g[to].size())
		{
			if(g[to][j].flow > 0)
			{
				int from = g[to][j].to;
				cout << from-1 <<" "<< j+1 << endl;
			}		
		}
	}
}



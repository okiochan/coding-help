

int cap = 10;
int used[100];

int c[100][100];

int n = 5;
 
bool dfs (int s, int t, int cap)
{
	if( s == t ) return true;

	if( used[s] ) return false;

	used[s] = true;

	for(int i=0; i<=n; i++)
	{
		if( c[s][i] >= cap && dfs(i,t,cap) )
		{
			c[s][i] -= cap; c[i][s] += cap; 
			return true;
		}
	}

	return false;
}

int main()
{
freopen("inp.txt", "rb", stdin); 
//freopen("out.txt", "wt", stdout);
//unsigned int start_time =  clock();

int m; cin >> m;
FOR(i,0,m)
{
	int a,b, fl; cin >> a >> b >> fl;

	c[a][b] = fl;
}
    
int s = 1; int t = n;
int flow = 0;

while(cap)
{
	    memset(used,0,sizeof(used));

		if( dfs(s,t,cap) ) flow += cap;
		else cap /= 2;

}

cout << flow << endl;

	return 0;
}


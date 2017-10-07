
int parent[MAXN]; bool used[MAXN];

int find_set (int v) { // сжатие
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

//посчитать количество компонентов связности в графе
int getComponents()
{
  int n,m; scanf("%d %d", &n, &m);

  for(int i=1; i <= n; i++)
  parent[i] = i;

  FOR(i,0,m)
  {
	int a,b; scanf("%d%d",&a,&b);

    a = find_set (a); b = find_set (b);

	if (a != b)
		parent[b] = a;
  }

  int cnt = 0;
  for(int i=1; i <= n; i++)
  {
	int v = find_set(i);
	if( !used[v] )
	{
		used[v] = 1;
		cnt ++;
	}
   }

return cnt;
}

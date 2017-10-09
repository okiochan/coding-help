
vector<int> levit(int v1, int v2)
{

	vector<int> d (n, INF);
	d[v1] = 0;

	vector<int> id (n);
	deque<int> q;

	q.push_back (v1);
	vector<int> p (n, -1);

	while (!q.empty())
	{
		int v = q.front();  q.pop_front();
		id[v] = 1;

		for (int i=0; i<g[v].size(); i++)
		{
			int to = g[v][i].first, len = g[v][i].second;

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
	int v = p[v2];

	while(v != -1)
	{
		path.push_back(v);
		v = p[v];
	}

	reverse(path.begin(), path.end());
	return (path);
}










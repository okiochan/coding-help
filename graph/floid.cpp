struct Floid{
	int n;
	mat d;

	//mat incedence; at first d[i][j] = INF
	Floid(int n, mat d) : n(n), d(d) {}

	void solve() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	int dist(int a, int b) {
		return d[a][b];
	}
};
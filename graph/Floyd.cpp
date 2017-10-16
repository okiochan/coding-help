struct Floyd {
	int n;
	mat d;
	mat nxt;

	Floyd() {}
	//mat incedence; at first d[i][j] = INF
	Floyd(int n, mat d) : n(n), d(d) {
		nxt.assign(n, vec(n, -1));
		forn(i, 0, n)nxt[i][i] = i;
	}

	void solve() {
		forn(i, 0, n) {
			forn(j, 0, n) {
				if (d[i][j] != INF) {
					nxt[i][j] = j;
				}
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						nxt[i][j] = nxt[i][k];
					}

				}
			}
		}
	}

	void restore(int i, int j, vec&p) {
		for (; i != j; i = nxt[i][j]) {
			p.push_back(i);
		}
	}

	int dist(int a, int b) {
		return d[a][b];
	}
};
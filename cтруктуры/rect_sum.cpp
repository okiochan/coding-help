struct rectsum
{
	int S[504][504];
	int a[503][503];
	int n, m;

	rectsum(int n = 503, int m = 503) : n(n), m(m) {
		forn(i, 0, n) {
			forn(j, 0, m) {
				a[i][j] = 0;
			}
		}
		forn(i, -1, n) {
			forn(j, -1, m) {
				S[1 + i][1 + j] = 0;
			}
		}
	}

	int sum(int x1, int y1, int x2, int y2)
	{
		x1 += 1; y1 += 1; x2 += 1; y2 += 1;
		return (S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1]);
	}

	void add(int i, int j, int val) {
		a[i][j] += val;
	}

	void recalc()
	{
		forn(i, 0, n) {
			forn(j, 0, m) {
				S[1 + i][1 + j] = S[1 + i - 1][1 + j] + S[1 + i][1 + j - 1] - S[1 + i - 1][1 + j - 1] + a[i][j];
			}
		}
	}
}rs;
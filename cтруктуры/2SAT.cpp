

struct sat2 {
	mat g, gt;
	vec repr, order;
	string used;
	vec ans;
	int n;

	sat2(int n) :
		n(n),
		g(n),
		gt(n),
		repr(n),
		used(n, 0),
		ans(n)
	{}

	void imply(int a, int b) {
		g[a].push_back(b);
		g[b ^ 1].push_back(a ^ 1);
		gt[b].push_back(a);
		gt[a ^ 1].push_back(b ^ 1);
	}

	void topsort(int v) {
		used[v] = 1;
		for (auto u : g[v]) {
			if (!used[u]) topsort(u);
		}
		order.push_back(v);
	}

	void dfs(int v, int c) {
		used[v] = 1;
		repr[v] = c;
		for (auto u : gt[v]) {
			if (!used[u]) {
				dfs(u, c);
			}
		}
	}


	bool solve() {

		forn(i, 0, n) {
			if (!used[i]) {
				topsort(i);
			}
		}

		reverse(order.begin(), order.end());
		used.assign(n, 0);
		int c = 0;
		for (auto u : order) {
			if (!used[u]) {
				dfs(u, c);
				c++;
			}
		}

		bool can = 1;
		for (auto u : order) {
			if (repr[u] == repr[u ^ 1]) {
				can = 0; break;
			}
		}

		forn(i, 0, n) {
			if (repr[i] > repr[i ^ 1]) {
				ans[i] = 1;
			}
			else {
				ans[i] = 0;
			}
		}
		return can;
	}
};


Int main(Int argc, char * argv[])
{
#ifdef Home
	freopen("inp.txt", "rb", stdin);
#endif
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	sat2 st(2 * m);

	forn(i, 0, m) {
		int a, b; cin >> a >> b; a--; b--;

		ar[i][0] = a; ar[i][1] = b;
	}


	forn(i, 0, m) {
		forn(j, i + 1, m) {
			if (intersect(ar[i][0], ar[i][1], ar[j][0], ar[j][1])) {

				st.imply(2 * i, 2 * j + 1);
				st.imply(2 * i + 1, 2 * j);
			}
		}
	}


	if (st.solve()) {
		forn(i, 0, m) {
			if (st.ans[2 * i] == 1) cout << "i";
			else cout << "o";
		}
	}
	else
		cout << "Impossible\n";

	return 0;
}

struct rib {
    int from, to, flow, back_pos;
};

int n, m;

int S() { return 0; }
int Left(int i) { return S() + 1 + i; }
int Right(int i) { return Left(n) + 1 + i; }
int T() { return Right(n) + 1; }

struct MaxFlow {
    vector < vector <rib>> g;
    int n;
    vector<bool> used;

    MaxFlow(int n) : n(n) {
        g.resize(n);
    }

    void add_rib(int from, int to, int flow) {
        rib e1 = { from, to,flow,g[to].size() };
        rib e2 = { to,from,0,g[from].size() };
        g[from].push_back(e1);
        g[to].push_back(e2);
    }

    bool findFlow(int v, int cap) {
        if (v == T()) {
            return true;
        }
        used[v] = 1;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].to;
            if (!used[to] && g[v][i].flow >= cap && findFlow(to, cap)) {
                g[v][i].flow -= cap;
                g[to][g[v][i].back_pos].flow += cap;
                return true;
            }
        }
        return false;
    }

    int getMaxFlow() {
        int ans = 0;
        int cap = 1e6 + 1;
        while (cap > 0) {
            used.assign(n, 0);
            if (findFlow(S(), cap)) {
                ans += cap;
            } else {
                cap /= 2;
            }
        }
        return ans;
    }

    void printPath() { //!!!!!!!! change
        forn(i, 0, n) {
            int to = Right(i);
            forn(j, 0, g[to].size()) {
                if (g[to][j].flow > 0) {
                    int from = g[to][j].to;
                    cout << from - 1 << " " << j + 1 << endl;
                }
            }
        }
    }
};

void solve() {
    cin >> n >> m;
    MaxFlow mxf(n);

    forn(i, 0, n) {
        forn(j, 0, m) {
            int a, b; cin >> a >> b; a--; b--;
            mxf.add_rib(Left(a), Right(b), 1);
        }
    }

    forn(i, 0, n) {
        mxf.add_rib(S(), Left(i), 1);
    }
    forn(i, 0, n) {
        mxf.add_rib(Right(i), T(), 1);
    }

    int ans = mxf.getMaxFlow();
}

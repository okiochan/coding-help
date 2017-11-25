struct sat2 {
    mat g, gt;
    vec repr, order, ans;
    string used;
    int n;

    sat2(int n) : n(n), g(n), gt(n), repr(n), used(n, 0), ans(n) {}

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
            if (used[u]) continue;
                dfs(u, c);
        }
    }
    bool solve() {
        forn(i, 0, n) {
            if (used[i]) continue;
                topsort(i);
        }
        reverse(order.begin(), order.end());
        used.assign(n, 0);
        int c = 0;
        for (auto u : order) {
            if (used[u]) continue;
                dfs(u, c);
                c++;
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
            } else {
                ans[i] = 0;
            }
        }
        return can;
    }
};


struct pt {
    int st, en;
    pt(int st, int en) :st(st), en(en) {}
    pt() {}
};

struct segUpd {
    vec balance;
    vector <pt> v;
    int n;
    segUpd(int n) : n(n) {
        balance.assign(n, 0);
        v.assign(n, pt(0,0));
    }
    void addSeg(int l, int r) {
        v[l].st += 1; v[r].en += 1;
    }
    // (a,b)
    void solve() {
        int bal = 0;
        forn(i, 0, n) {
            bal -= v[i].en;
            balance[i] = bal;
            bal += v[i].st;
        }
    }
    int getBal(int pos) {
        return balance[pos];
    }
};

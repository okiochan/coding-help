#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <set>
#include <map>
using namespace std;
#define forn(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define mp make_pair
#define ff first
#define ss second
#define whats(a) cerr<<#a<<" "<<a<<endl;
#define Mod(a,b) (((a)%(b)+(b))%(b))
#define sz(x) (int((x).size()))
typedef long long ll;
typedef int Int;
int ni() { int a; scanf("%d", &a); return a; }
//#define int ll
 
const int N = (int)1e6 + 3;
 
struct tree {
    vector<int> t;
    int ds;
    tree(int n) {
        for (ds = 1; ds < n; ds *= 2);
        t.assign(2 * ds + 1, 0);
    }
 
    void update(int x, int val) {
        t[x + ds] = val;
        for (int i = x + ds; i >= 2; i /= 2) {
            t[i / 2] = t[i / 2*2] + t[i / 2 * 2+1];
        }
    }
 
    int query(int l, int r) {
        int ret = 0;
        l += ds;
        r += ds;
        for (; l <= r;) {
            if (l & 1)ret += t[l];
            if (!(r & 1))ret += t[r];
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
 
        return ret;
    }
 
};
 
Int main(Int argc, char * argv[])
{
#ifdef Home
    freopen("inp.txt", "rb", stdin);
#endif
    ios::sync_with_stdio(0);
 
    int n = 10;
    tree t(n);
    forn(i, 0, n) {
        t.update(i, i);
    }
    forn(i, 0, n) {
        cout << t.query(0, i) << endl;
    }
   
    return 0;
}
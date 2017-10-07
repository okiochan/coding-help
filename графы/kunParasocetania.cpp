#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int n, k,cnt;
vector<int>  g[100];
vector<int> para;
vector<int> used;
 
bool try_kuhn (int v) {
  used[v] = true;

	for (int i=0; i<g[v].size(); i++){
		int to = g[v][i];

		if(!used[to] ){
		 used[to]=1;

		  if(para[to] == -1 || try_kuhn (para[to])){
			 para[to] = v;
			 para[v]=to;
			return true;
		  }

		used[to]=0;
		}
	}
	return false;
}

int main() {
freopen("input.txt", "rt", stdin);
freopen("output.txt","wt",stdout);
cin >> n >> k;

for(int i=0; i< k; i++){
	int a,b; cin >> a >> b;
	g[a].push_back(b); g[b].push_back(a);
}

for(int r=0; r<30  ; r++){
 cnt=0;
 for(int y=0; y<n; y++)
		random_shuffle(g[y].begin(), g[y].end());

para.assign(n, -1); int cnt=0;
	for (int v=0; v<n; ++v) 
		if( para[v] == -1){
		  used.assign (n, false);
		  if(try_kuhn(v)) cnt++;
		}
	
 cout << cnt << endl;
	//for (int i=0; i<n; ++i)
	//		printf ("%d %d\n", para[i], i);
}

fclose(stdin);
fclose(stdout);
return 0;
}
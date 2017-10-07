#include <iostream>
using namespace std;

int n,a,b, m, t, q;

int d[110][110];

int main() {

	cin >> t;
	while(t--){
	cin >> n >> m;

	for(int i=1; i <= n; i++)
		for(int j =1; j <= n; j++){
			if(i == j) d[i][j] = 0;
			else d[i][j] = 8;
		}

	for(int i=1; i <= m; i++){
			cin >> a >> b;
			if(a != b){d[a][b] = 1; d[b][a] = 1;}
		}

	for (int k=1; k<=n; k++)
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if(d[i][k] < 8 && d[k][j]  < 8 && i != j) d[i][j] = (d[i][j] < d[i][k] + d[k][j] ? d[i][j] : 1 );

	cin >> q;
	while(q--){
		cin >> a >> b;
	      if(d[a][b] == 8) cout << 0 << endl;
		  else cout << 1 << endl;
	}

	}
	return 0;
}
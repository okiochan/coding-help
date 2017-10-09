#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = (int)1E9;

#define FOR(i,s,f) for(int i=s; i<f; i++)
#define BFOR(i,s,f) for(int i=f-1; i>=s; i--)
const int MOD = 256;
#define MAXN 100
//********************

int n,m;
vector <int> g[MAXN];

int dp[MAXN][2]; // наибольшее количество независимых множеств в поддереве i 
//если j=1, то i брать нельзя (если взяли предка)

int solve(int cur, int can , int p){
	 if(dp[cur][can] == -1){
		 dp[cur][can] = 0;
		   if(can){
			   int res=1; 
			   FOR(i,0,g[cur].size()){
				   int u=g[cur][i];
				    if(u != p)
						res += solve(u,0,cur);

						dp[cur][can] = max(dp[cur][can],res);
			   }
		   }
		   return dp[cur][can];
	 }
	 {
		 int res=0;
		    FOR(i,0,g[cur].size()){
				   int u=g[cur][i];
				    if(u != p)
						res += max(u,1,cur);

						dp[cur][can] = max(dp[res][cur],res);
			   }
	 }
}

int main(){
freopen("input.txt", "rt", stdin);
freopen("output.txt","wt",stdout);

int m, a, b;
	cin >> n >> m;

	// чтение ДЕРЕВА
	FOR(i,0,m){
		cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
	}


fclose(stdin);
fclose(stdout);
	return 0;
}

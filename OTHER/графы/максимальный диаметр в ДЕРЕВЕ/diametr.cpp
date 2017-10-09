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
int res[MAXN]; //������������ ������� �� ������� ������� , ����� �� ������ ����� � �������,
//�� ������� ��� ����� �������

int path[MAXN]; // ����� ������� ���� ���� �� ������� �������

void diametr(int u, int p){ //u - �� ���� ��������� p - �� ������

	vector <int> child;
	child.push_back(0); // ���������, �� ���� ����� ������������ �������� � �����������

	FOR(i,0, g[u].size()){
		int togo = g[u][i]; 

		if(togo != p){
			diametr(togo,u); 

			res[u]=max(res[u], res[togo]);
			path[u]=max(path[u], path[togo]+1);

			child.push_back(path[togo]+1);
		}
	}
		if(child.size() > 1){
			sort(child.rbegin(), child.rend()); //�� ��������
			res[u] = max(res[u], child[0]+child[1]); // ����� ���� ������������ ����
		}	
}//end ff


int main(){
freopen("input.txt", "rt", stdin);
freopen("output.txt","wt",stdout);

int m, a, b;
	cin >> n >> m;

	// ������ ������
	FOR(i,0,m){
		cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
	}

	diametr(1,1);

fclose(stdin);
fclose(stdout);
	return 0;
}

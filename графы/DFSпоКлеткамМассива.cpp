#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = (int)1E9;

#define FOR(i,s,f) for(int i=(s); i<f; i++)
#define MAXN 550
//********************
int n,m; //n - ������ m - �������
char g[MAXN][MAXN]; //��� ������, ����� ��������

// ��� ���, ��������� � ����
bool path[MAXN][MAXN];
                  
                 //l   t  r  b
int dir[2][4] = {{-1, 0, 1, 0}, 
                 {0, 1, 0, -1}};
#define noway(x,y) (x<0 || y<0 || x>=m || y>=n) // ����� �� ������� �������

void dfs(int y, int x){
	path[y][x]=1;

	  FOR(i,0,4){ // �� ���� ������� ������������
		  int xx = x+dir[0][i]; int yy= y+dir[1][i];
		  if(noway(xx,yy) || path[yy][xx])continue; //����� �� ������� ��� ��� �������

		  dfs(yy,xx);
	  }
	return;
}

int main(){
//freopen("input.txt", "rt", stdin);
//freopen("output.txt","wt",stdout);

	cin >> n >> m;
	FOR(i, 0, n) scanf("%s", g[i]); //������� ������

	int sX, sY, eX, eY; cin >> sY >> sX >> eY >> eX; //��������� � �������� ������
	sX--; sY--; eX--; eY--;
	dfs(sY, sX);

//fclose(stdin);
//fclose(stdout);
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = (int)1E9;

#define FOR(i,s,f) for(int i=(s); i<f; i++)
#define MAXN 550
//********************
int n,m; //n - строки m - столбцы
char g[MAXN][MAXN]; //сам массив, задан строками

// где был, нумерация с нуля
bool path[MAXN][MAXN];
                  
                 //l   t  r  b
int dir[2][4] = {{-1, 0, 1, 0}, 
                 {0, 1, 0, -1}};
#define noway(x,y) (x<0 || y<0 || x>=m || y>=n) // выход за пределы массива

void dfs(int y, int x){
	path[y][x]=1;

	  FOR(i,0,4){ // по всем четырем направлениям
		  int xx = x+dir[0][i]; int yy= y+dir[1][i];
		  if(noway(xx,yy) || path[yy][xx])continue; //выход за границы или уже посещал

		  dfs(yy,xx);
	  }
	return;
}

int main(){
//freopen("input.txt", "rt", stdin);
//freopen("output.txt","wt",stdout);

	cin >> n >> m;
	FOR(i, 0, n) scanf("%s", g[i]); //считать массив

	int sX, sY, eX, eY; cin >> sY >> sX >> eY >> eX; //стартовая и конечная клетки
	sX--; sY--; eX--; eY--;
	dfs(sY, sX);

//fclose(stdin);
//fclose(stdout);
	return 0;
}
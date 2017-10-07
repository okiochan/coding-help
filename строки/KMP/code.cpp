#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
#include <queue>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
const int INF = (int)1E9+10;
const int MOD = (int)1E9+7;

const int MAXN = 1e6 + 10;
#define FOR(i,s,f) for(int i=s; i < f; i++)
#define mp make_pair
#define M_PI 3.1415926535897932384626433832795
// oeis.org 

//line : A = y2-y1;  B = x1-x2; C = x1*y1-x1*y2+x2*y1-x1*y1;
//******************************

char a[MAXN], b[MAXN], d[MAXN];
int piA[MAXN], piB[MAXN];

/*void prefix_function (string s, int *pi) 
{
	int n =  s.length();
	
	for (int i=1; i<n; i++)
	{
		int j = pi[i-1];

		while (j > 0 && s[i] != s[j])
			j = pi[j-1];

		if (s[i] == s[j])  j++;
		pi[i] = j;
	}
}*/

int seek_substring_KMP (char s[], char p[])
{
	int i, j, N, M;
	N = strlen(s);
	M = strlen(p);

	/* Вычисление префикс-функции */
	d[0]=0;
	for(i=1,j=0;i<M;i++)
	{
		while(j>0 && p[j]!=p[i])
			j = d[j-1];
		if(p[j]==p[i])
			j++;
		d[i]=j;
	}

	/* поиск */
	for(i=0,j=0;i<N; i++)
	{
		while(j>0 && p[j]!=s[i])
			j=d[j-1];
		if(p[j]==s[i])
                        j++;
		if (j==M)
                {
                        return i-j+1;
                }
	}
	return -1;
}

int main()
{   
//freopen("input.txt", "rt", stdin); freopen("output.txt","wt",stdout);

memset(piA, 0 , sizeof(piA));

scanf("%s", a);
scanf("%s", b);

if(seek_substring_KMP (a, b) == -1) cout << "NEW\n";
else cout << "OLD\n";

//fclose(stdin); fclose(stdout);
    return 0;
}
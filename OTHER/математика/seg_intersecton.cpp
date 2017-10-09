#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>  
#include <string>
using namespace std;
  
typedef long long ll;
const int INF = (int)1E9 + 10;
const double EPS = 1E-9;
const int MAXN = (int)(500010);
const int MOD = (int)(1e5 + 7);
  
#define mp make_pair 
#define FOR(i,s,f) for(int i=s; i<f; i++)
#define BFOR(i,s,f) for(int i= (f-1); i>=s; i--)
  
//int dir[2][4] = {{ -1, 0, 1, 0 }, 
//                 { 0, 1, 0, -1 }}; 
//************************************************
  
struct pt 
{ 
    int x,y; 
    pt(const int x, const int y) : x(x), y(y) {}
  
    static pt read() 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        return pt(x,y);
    }
};
  
struct Line
{
     int a,b,c;
     Line(const int a, const int b, const int c) : a(a), b(b), c(c) {}
  
     int value(const pt &p) const 
     {
         return a*p.x+b*p.y+c; // 0 => точка лежит на прямой
     }
};

// лежит ли точка между проекциями точек отрезка на коорд. ось ( Ох или Оу) ?  
bool between(int l, int r, int x)
{
 return min(l,r) <= x && x <= max(l,r);
}
  
struct Seg
{
    pt a,b;
    Seg(const pt &a, const pt &b) :a(a), b(b) {}
  
    static Seg read()
    {
        return Seg( pt::read(), pt::read() );
    }
  
    Line getLine() const// вернуть коэф-ты из ур-я прямой вида Ax + By + C = 0
    {
        int A=b.y-a.y; int B = a.x-b.x; int C = a.y*b.x-a.x*b.y;
        return Line(A,B,C);
    }
  
    // 1)точка лежит на прямой ? И 2) коорд. Х точки лежит между коорд-ми Ха и Хб отрезка (проекции на Ох) ? 3) У точки между Уа и Уб ?
     bool contains(const pt &p)
     {
         return getLine().value(p) == 0 && between( a.x, b.x, p.x) && between( a.y, b.y, p.y);
     } 
};
  
 
void init()
{
Seg seg1 = Seg::read();
Seg seg2 = Seg::read();
  
Line A = seg1.getLine(), B = seg2.getLine();
 
//если точки в разных полупл-х относительно прямой, то при подстановке их(точек) в ур-е прямой, знаки будут отличаться
//если знаки различны, то value(точка 1) * value(точка 2) < 0
double val1 = (double)A.value(seg2.a) * A.value(seg2.b);
double val2 = (double)B.value(seg1.a) * B.value(seg1.b); 
  
if(  val1 < 0 && val2 < 0 )  printf("Yes\n"); //строчки выше
 
// есть ли в отрезке сег точка другого отрезка
else if( seg1.contains(seg2.a) )  printf("Yes\n");
else if( seg1.contains(seg2.b) )  printf("Yes\n");
else if( seg2.contains(seg1.a) )  printf("Yes\n");
else if( seg2.contains(seg1.b))  printf("Yes\n");
else
    printf("No\n");
 
}
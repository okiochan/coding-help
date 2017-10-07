//делится ли строка нацело на n
//1 - yes
bool isDivisible(string s, int n)
{
 int a = s[0]-'0';

FOR(i,1,s.size())
{
	a = (a*10 + (s[i]-'0'))%n;
}

if( a == 0 ) return 1;
return 0;
}
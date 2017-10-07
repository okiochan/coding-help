
gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int lcm (int a, int b) 
{
	return a / gcd (a, b) * b;
}

//gcd(a,b,c) = gcd( gcd(a,b), c);
//lcm(a,b,c) = lcm( lcm(a,b), c);

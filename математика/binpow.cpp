
int binpow(int a, int n){
	if(n == 0) return 1;
	if(n%2==0){
		int b = binpow(a,n/2);
		return b*b;
	}
	else{
		int b = binpow(a,n-1);
		return b*a;
	}
}

int binpow (int a, int n) {
	int res = 1;
	while (n) {

		if (n & 1)
			res *= a;

		a *= a;
		n >>= 1;
	}
	return res;
}

ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {

		if (n & 1)
			res *= a;

		a *= a;
		n >>= 1;
	}
	return res;
}

ll binpow_mod(ll a,ll n,ll m){
ll r=1;
a%=m;
while (n){
  if (n&1)
     r=(r*a)%m;

a=(a*a)%m;
n>>=1; 
}
return r;
}

ll fact[MAXN]; // факториал i-го числа

//посчитать факториалы до n вкл
void initFact(int n){ 
	 fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (int) (((ll)fact[i - 1] * i) % MOD);
    }
}

//бин возв в сетпень по модулю (a^n) % m --> 1<=a,n,m<=10^18
int binpow_mod(ll a,ll n){
ll r=1;
a %= MOD;
while (n){
  if (n&1) // n%2 != 0
     r=(r*a)%MOD;

a=(a*a)%MOD;
n>>=1;  // n/=2
}
return r;
}

//C из n по k --------------------------
//с предпросчетом факториалов, по модулю
int C(int n, int k) { 
    return (int) (((((long long)fact[n] * binpow_mod(fact[n - k], MOD - 2)) % MOD) * binpow_mod(fact[k], MOD - 2)) % MOD);
}

//с модулем не пашет
ll C(ll n, ll k){

	ll res = 1;
	for(ll i = 0; i < (n-k); i++){
		res *= (n-i); res /= (i+1);
	   }

	return res;
}

//-----------------------

int factmod (ll n, ll p) {
ll res = 1;
while (n > 1) {
res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
for (int i=2; i<=n%p; ++i)
res = (res * i) % p;
n /= p;
}
return res % p;
}
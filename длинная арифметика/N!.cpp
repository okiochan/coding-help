
int solonginteger[MAXN];
int endd=0;

void multiply(int ch){
	int max = ch * 2.7;

	for(int i = 0; i < max && ch > 0; i++)
		solonginteger[i] *= ch;
	
	for(int i = 0; i < max; i++){

		while(solonginteger[i] > 9){

			solonginteger[i + 1] += solonginteger[i]/10;
			solonginteger[i] = solonginteger[i] % 10;
			
		}
	}
	return;
}

void Fa( int n){
	FOR(i,0,MAXN) solonginteger[i] = 0;
	solonginteger[0] = 1;
	for(int fa = 1; fa <= n; fa ++)
	multiply(fa);

	endd = (n*2.7) - 1;
	while( solonginteger[endd] == 0) endd--;

	for(int k = endd ; k >= 0; k--) cout << solonginteger[k]; cout << endl;
}
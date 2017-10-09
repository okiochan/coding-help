

ll simple[MAXN]; // здесь решето
vector <ll> ans; // здесь будут множители

void init(int n){
//решето Ёратосфена 
for(int i=2; i*i < MAXN1; i++){
  if(!simple[i])
	for(int j = i*i; j < MAXN1; j+=i){
		if(!simple[j])simple[j]=i;
	}
}

while(simple[n]){ans.push_back(simple[n]); n/=simple[n];}

}


ll simple[MAXN]; // ����� ������
vector <ll> ans; // ����� ����� ���������

void init(int n){
//������ ���������� 
for(int i=2; i*i < MAXN1; i++){
  if(!simple[i])
	for(int j = i*i; j < MAXN1; j+=i){
		if(!simple[j])simple[j]=i;
	}
}

while(simple[n]){ans.push_back(simple[n]); n/=simple[n];}

}
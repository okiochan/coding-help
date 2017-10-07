const int N=550; // макс значение

vector<int> g[N*N]; // сам граф

cin >> n >> m ; // n - строки m - столбцы

// create graf
    for(int i=0; i< n; i++) // индексация с нуля
	  for(int j=0; j < m; j++){
		  int v = i*m+j; 
		  if(j+1<m) g[v].push_back(v+1);
		  if(i+1<n) g[v].push_back(v+m);
		  if(j-1>=0) g[v].push_back(v-1);
		  if(i-1>=0) g[v].push_back(v-m);
	  }
//имена вершин от 0 до n*m-1
const int N=550; // ���� ��������

vector<int> g[N*N]; // ��� ����

cin >> n >> m ; // n - ������ m - �������

// create graf
    for(int i=0; i< n; i++) // ���������� � ����
	  for(int j=0; j < m; j++){
		  int v = i*m+j; 
		  if(j+1<m) g[v].push_back(v+1);
		  if(i+1<n) g[v].push_back(v+m);
		  if(j-1>=0) g[v].push_back(v-1);
		  if(i-1>=0) g[v].push_back(v-m);
	  }
//����� ������ �� 0 �� n*m-1

 
int n, m;
int used[MAXN], path[MAXN];
vector <int> g[MAXN];

int ciclEnd, ciclStart = -1;

//был цикл - тру
bool dfs (int v) {
    used[v] = 1;

    for (int i=0; i<g[v].size(); i++) {
        int togo = g[v][i];

         if (used[togo] == 0) {
            path[togo] = v;
            if (dfs(togo)) return true; //если был цикл           
         }
         else if (used[togo] == 1) { //нашелся цикл 
                 ciclEnd = v;
                 ciclStart = togo;
                   return true;
               }
   }
    used[v] = 2; //не дошли до цикла и прошли все ребра
    return false;
}

int main() {


	cin >> n >> m;


	for(int i=1; i <= m; i++){
	  int a, b; cin >> a >> b;
          g[a].push_back(b);
        }


	//if ciclic?
	 for(int i=1; i <= n; i++) if(dfs(i))break;
	 

	
	 if(ciclStart == -1) cout <<"acycled" << endl;
	  else{
		cout <<"cycled" << endl;
                  
                  vector<int> cycle;
		
                    cycle.push_back (ciclStart);
                      for (int v = ciclEnd; v!=ciclStart; v=path[v]) cycle.push_back (v);
                    cycle.push_back (ciclStart);

		    reverse(cycle.begin(), cycle.end()); //! в обратном порядке
		      for(int i=0; i<cycle.size(); i++) cout << cycle[i] << " ";
		      cout << endl;
    }
   


	return 0;
}
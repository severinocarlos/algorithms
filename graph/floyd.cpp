int P, R;
const int MAXN = 50 + 5;
vector<vector<int>> adj(MAXN, vector<int>(MAXN, 0));
vector<vector<ll>> dist(MAXN, vector<ll>(MAXN));

void floyd() {
	for (int i = 0; i < P; i++) {
    	for (int j = 0; j < P; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
   	}
	}

	for (int k = 0; k < P; k++) {
	   for (int i = 0; i < P; i++) {
	      for (int j = 0; j < P; j++) {
	         dist[i][j] = min(dist[i][j], 
	                              dist[i][k] + dist[k][j]);
	      }
	  	}
	}
}
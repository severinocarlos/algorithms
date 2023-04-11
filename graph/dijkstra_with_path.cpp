vector<vector<pii>> adj(MAXN);
vector<int> parents;
vector<int> ans;

void dijkstra(int s, int f) {
    parents.assign(f + 1, -1); // indexed at 1
    vector<ll> dist(MAXN, INF); dist[s] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});

 	while (!pq.empty()) {
     	pli vtx = pq.top(); pq.pop();
     	ll w = vtx.fi; int u = vtx.se;

     	if(w > dist[u]) continue;
     	for (auto v : adj[u]) {
         if (dist[u] + v.se < dist[v.fi]) {
            dist[v.fi] = dist[u] + v.se;
            parents[v.fi] = u; // [children] = root 
            pq.push({dist[v.fi], v.fi});
         }
      }
   }
}

bool build_way(int n) {
    int node = n;
	ans.pb(node);
	
	while (node != 1) {
		if (parents[node] == -1) {
			return false;
		}
		ans.pb(parents[node]);
		node = parents[node];
	}
    return true;
}
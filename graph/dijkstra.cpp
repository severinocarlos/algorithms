vector<vector<pii>> adj;

// O ((V + E)Log V )
void dijkstra(int s) {
    vector<ll> dist(MAXN, INF); dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        pii vtx = pq.top(); pq.pop();
        int w = vtx.fi, u = vtx.se;

        if(w > dist[u]) continue;
        for (auto v : adj[u]) {
            if (dist[u] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[u] + v.se;
                pq.push({dist[v.fi], v.fi});
            }
        }
    }
}
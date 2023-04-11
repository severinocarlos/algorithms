vector<vector<int>> adj;
vector<bool> vis;

// O(V + E)
void bfs(int source){
    queue<int> q;
    vis.assign(MAXN, false);
    q.push(source);
    vis[source] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto v: adj[u]){
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

// Traverse all the Graph (Disconnected Graph)
// void traverse(){
//     vis.assign(MAXN, false);
//     for (int i = 0; i < MAXN; i++) {
//         if (!vis[i]) bfs(i);
//     }
// }
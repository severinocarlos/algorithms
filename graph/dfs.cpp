vector<vector<int>> adj;
vector<bool> vis;

// O (V + E)
void dfs(int v){
    vis[v] = true;
    for(auto u: adj[v]){
        if (!vis[u]) dfs(u);
    }
}

// Traverse all the Graph (Disconnected Graph)
// traverse each node
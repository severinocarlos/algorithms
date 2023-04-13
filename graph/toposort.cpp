vector<int> adj(MAXN);
bool vis[MAXN];
stack<int> S;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
    S.push(u);
}

// S is the answer
// Traverse all the Graph (Disconnected Graph)
// traverse each node
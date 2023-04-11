vector<int> adj(ms);
vector<int> colour(ms, -1);


void dfs(int u) {
    for (int v : adj[u]) {
        if (colour[v] == -1) {
            colour[v] = 1 - colour[u];
            dfs(v);
        }
    }
}

// call paintAll in main
void paintAll(int n){
    for (int u = 0; u < n; ++u) {
        if (colour[u] == -1) {
            colour[u] = 0;
            dfs(u);
        }
    }
}

bool ok(int n) {
    bool is_bicolorable  = true;
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            is_bicolorable  = is_bicolorable  && colour[u] != colour[v];
        }
    }
    return is_bicolorable;
}

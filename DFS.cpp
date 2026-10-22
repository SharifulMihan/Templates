vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src) {
    vis[src] = true; // Mark current node visited
    cout << src << " ";

    for (int child : adj_list[src]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    memset(vis, false, sizeof(vis));
    int n, e;
    if (!(cin >> n >> e)) return 0;
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // Undirected graph
    }
    int src;
    cin >> src;
    dfs(src);
    return 0;
}

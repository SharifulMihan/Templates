vector<int> adj_list[1005];
bool vis[1005];
int level[1005]; // Stores shortest path distance in edges

void bfs(int src) {
  queue<int> q;
  q.push(src);
  vis[src] = true;
  level[src] = 0; // Distance from source to source is 0

  while (!q.empty()) {
    int par = q.front(); // Current node
    q.pop();
    cout << par << " ";

    // Traverse all neighboring nodes
    for (int child : adj_list[par]) {
      if (!vis[child]) {
        q.push(child);
        vis[child] = true;
        level[child] = level[par] + 1; // Distance + 1
      }
    }
  }
}

int main() {
  memset(vis, false, sizeof(vis));
  memset(level, 0, sizeof(level));
  int n, e;
  if (!(cin >> n >> e)) return 0;
  while (e--) {
    int a, b; cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a); // Undirected graph
  }
  int src; cin >> src;
  bfs(src);
  return 0;
}

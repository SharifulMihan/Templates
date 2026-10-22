#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// Global variables
vector<int> adj_list[1005];
bool vis[1005];
int level[1005]; // Stores shortest path distance in edges

// Breadth-First Search (BFS) function
void bfs(int src) {
  queue<int> q;
  q.push(src);
  vis[src] = true;
  level[src] = 0; // Distance from source to source is 0

  while (!q.empty()) {
    int par = q.front(); // Current node
    q.pop();
    cout << par << " "; // Print the visited node

    // Traverse all neighboring nodes
    for (int child : adj_list[par]) {
      if (!vis[child]) {
        q.push(child);
        vis[child] = true;
        level[child] = level[par] + 1; // Distance + 1
      }
    }
  }
  cout << endl; // Print a newline after all reachable nodes are visited
}

int main() {
  // Initialize 'vis' and 'level' arrays with zeros using memset
  memset(vis, false, sizeof(vis));
  memset(level, 0, sizeof(level));

  int n, e; // Number of nodes and edges
  if (!(cin >> n >> e)) return 0; // Read nodes and edges, handle error if input fails

  // Read edges and build the undirected graph using adjacency list
  while (e--) {
    int a, b; // Edge connected between node 'a' and node 'b'
    if (!(cin >> a >> b)) break; // Handle error if edge input fails
    adj_list[a].push_back(b);
    adj_list[b].push_back(a); // Undirected graph means edges work both ways
  }

  int src; // Source node for BFS
  if (cin >> src) {
    bfs(src); // Perform BFS traversal starting from the source node
  }

  return 0;
}

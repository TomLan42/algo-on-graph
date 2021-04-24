#include <iostream>
#include <vector>

using std::vector;
using std::pair;


// adj is the adj list
// x is the starting vertice
// y is the target vertice
int reach(vector<pair<vector<int>, bool > > &adj, int x, int y) {
  
  if (x == y) {
    return 1;
  }

  // visit
  adj[x].second = true;
  
  int result = 0;
  for (int i = 0; i < adj[x].first.size(); ++i) {
    if (!adj[adj[x].first[i]].second) {
      // dfs
      result = result | reach(adj, adj[x].first[i], y);
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<pair<vector<int>, bool > > adj(n, std::make_pair(vector<int>(), false));
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].first.push_back(y - 1);
    adj[y - 1].first.push_back(x - 1);;
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}

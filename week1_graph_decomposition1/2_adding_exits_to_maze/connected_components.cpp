#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void reach(vector<pair<vector<int>, bool > > &adj, int x) {

  // visit
  adj[x].second = true;
  for (int i = 0; i < adj[x].first.size(); ++i) {
    if (!adj[adj[x].first[i]].second) {
      reach(adj, adj[x].first[i]);
    }
  }
}



int number_of_components(vector<pair<vector<int>, bool > > &adj) {
  
  int res = 0;
  for (int i = 0; i < adj.size(); ++i) {
    if (!adj[i].second) {
      res++;
      reach(adj,i);
    }
  }
  return res;
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
  std::cout << number_of_components(adj);
}

// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Recursive function for dfs implementation
  void dfs(int node, vector<int> adj[], vector<int> &ans, vector<bool> &visited)
  {
    visited[node] = 1;
    ans.push_back(node);

    for (int i = 0; i < adj[node].size(); i++)
    {
      if (!visited[adj[node][i]])
      {
        visited[adj[node][i]] = 1;
        dfs(adj[node][i], adj, ans, visited);
      }
    }
  }

  // Function to return a list containing the DFS traversal of the graph.
  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    vector<int> ans;
    vector<bool> visited(V, 0);
    dfs(0, adj, ans, visited);
    return ans;
  }
};

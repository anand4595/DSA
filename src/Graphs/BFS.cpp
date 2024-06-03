// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
#define NODE_START 0
using namespace std;

class Solution
{
  void BFS(vector<int> adj[], vector<bool> &visited, vector<int> &traversal, int startNode = NODE_START)
  {
    if (visited[startNode])
    {
      return;
    }

    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
      int currentNode = q.front();
      q.pop();
      traversal.push_back(currentNode);
      for (int node : adj[currentNode])
      {
        if (!visited[node])
        {
          q.push(node);
          visited[node] = true;
        }
      }
    }
  }

public:
  vector<int> bfsOfGraph(int V, vector<int> adj[])
  {
    vector<bool> visited(V + NODE_START, false);
    vector<int> traversal;
    BFS(adj, visited, traversal);
    return traversal;
  }
};
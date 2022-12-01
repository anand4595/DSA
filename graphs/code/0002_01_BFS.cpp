#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
    void BFS(int n,vector<bool> &visited,vector<int> adj[],vector<int> &traversal){
        if (visited[n]) return;
        queue<int> q;
        q.push(n);
        visited[n] = 1;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            traversal.push_back(node);
            for (int i : adj[node]){
                if (!visited[i]){ 
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> traversal;
        int start = 0;
        vector<bool> visited(V+start,0);
        BFS(start,visited,adj,traversal);
        return traversal;
    }
};
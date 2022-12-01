// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void DFS(int n,vector<int> adj[],vector<bool> &visited,vector<int> &traversal){
        if (visited[n]) return;
        traversal.push_back(n);
        visited[n] = 1;
        for (int i : adj[n]){
            DFS(i,adj,visited,traversal);
        }
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int start = 0;
        vector<bool> visited(V+start,0);
        vector<int> traversal;
        DFS(start,adj,visited,traversal);
        return traversal;
    }
};
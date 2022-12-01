#include <iostream>
#include <vector>
using namespace  std;

using vi = vector<int>;
using vvi = vector<vi>;

int main () {
    int n,m;
    cin >> n >> m;
    vvi adj(n+1,vi(n+1,0));
    for (int i = 0; i < m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
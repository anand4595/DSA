#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> ls(n+1);
    for (int i = 0; i < m;i++){
        int u,v;
        cin >> u >> v;
        ls[u].push_back(v);
        ls[v].push_back(u);
    }
}
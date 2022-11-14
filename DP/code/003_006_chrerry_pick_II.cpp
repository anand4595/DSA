#include <vector>
using namespace std;

using v = vector<int>;
using vv = vector<v>;
using vvv = vector<vector<vector<int>>>;

class Solution_recursion {
public:
int f(int a,int b,int r,vv &grid){
    if (r == grid.size()) return 0;
    if (a==-1 || a==grid[0].size() || b==-1 || b==grid[0].size()) return -1e9;
    int maxi = -1e9;
    for (int del_a = -1;del_a <= 1;del_a++){
        for (int del_b = -1;del_b <= 1;del_b++){
            if (a == b) maxi = max(maxi,grid[r][b]+f(a+del_a,b+del_b,r+1,grid));
            else maxi = max(maxi,grid[r][a]+grid[r][b]+f(a+del_a,b+del_b,r+1,grid));
        }
    }
    return maxi;
}
};

class Solution_memo {
public:
int f(int a,int b,int r,vv &grid,vvv &dp){
    if (r == grid.size()) return 0;
    if (a==-1 || a==grid[0].size() || 
    b==-1 || b==grid[0].size()) return -1e9;
    if (dp[a][b][r] != -1) return dp[a][b][r];
    int maxi = -1e9;
    for (int del_a = -1;del_a <= 1;del_a++){
        for (int del_b = -1;del_b <= 1;del_b++){
            if (a == b) maxi = 
            max(maxi,grid[r][b]+f(a+del_a,b+del_b,r+1,grid,dp));
            else maxi = max(maxi,grid[r][a]+grid[r][b]+
            f(a+del_a,b+del_b,r+1,grid,dp));
        }
    }
    return dp[a][b][r] = maxi;
}
};

class Solution_tab {
public:
int f(vvv &grid){
    int r = grid.size();
    int c = grid[0].size();
    int dp[r][c][c];

}
};

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    Solution_memo obj;
    vector<vector<vector<int>>> dp(c,vector<vector<int>>(c,vector<int>(r,-1)));
    return obj.f(0,grid[0].size()-1,0,grid,dp);
}
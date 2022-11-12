#include <vector>
using std::min;
using std::vector;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution_recursive {
public:
int f(int x,int y,vvi &grid){
    if (!x && !y) return grid[0][0];
    if (x < 0 || y < 0) return 1e9;
    return grid[x][y] + min(f(x-1,y,grid),f(x,y-1,grid));
}
};

class Solution_memo {
public:
int f(int x,int y,vvi &grid,vvi &dp){
    if (!x && !y) return grid[0][0];
    if (x < 0 || y < 0) return 1e9;
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = grid[x][y] + min(f(x-1,y,grid,dp),f(x,y-1,grid,dp));
}
};

class Solution_tab {
public:
int f(vvi &grid){
    int xLen = grid.size();
    int yLen = grid[0].size();
    vvi dp(xLen,vi(yLen));
    for (int i = 0; i < xLen;i++){
        for (int j = 0; j < yLen;j++){
            if (i == 0 && j == 0) {
                dp[0][0] = grid[0][0];
                continue;
            }
            int left = j > 0? dp[i][j-1]:1e9;
            int down = i > 0? dp[i-1][j]:1e9;
            dp[i][j] = grid[i][j] + min(left,down);
        }
    }
    return dp[xLen-1][yLen-1];
}
};

class Solution_space_opt {
public:
int f(vvi &grid){
    int xLen = grid.size();
    int yLen = grid[0].size();
    vi p(yLen),c(yLen);
    for (int i = 0; i < xLen; i++){
        for (int j = 0; j < yLen;j++){
            if (!i && !j){
                c[0] = grid[0][0];
                continue;
            }
            int left = j > 0?c[j-1]:1e9;
            int down = i > 0?p[j]:1e9;
            c[j] = grid[i][j] + min(left,down);
        }
        p = c;
    }
    return c[yLen-1];
}
};

int minSumPath(vector<vector<int>> &grid) {
    Solution_memo obj;
    int xLen = grid.size();
    int yLen = grid[0].size();
    vvi dp(xLen,vi(yLen,-1));
    return obj.f(xLen-1,yLen-1,grid,dp);
}
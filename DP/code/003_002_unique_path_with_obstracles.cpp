#include <vector>
using std::vector;

using vi = vector<int>;
using vvi = vector<vi>;
class Solution_rec {
public:
int f(int x,int y,vvi &grid){
    if (x < 0 or y < 0)  return 0;
    if (grid[x][y] == 1) return 0;
    if (x == 0 and y == 0) return 1;
    return f(x-1,y,grid) + f(x,y-1,grid);
}
};

class Solution_memo {
public:
int f(int x,int y,vvi &grid,vvi &dp){
    if (x < 0 or y < 0)  return 0;
    if (grid[x][y] == 1) return 0;
    if (x == 0 and y == 0) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = f(x-1,y,grid,dp) + f(x,y-1,grid,dp);  
}
};

class Solution_tab {
public:
int f(vvi &grid){
    int xLen = grid.size(), yLen = grid[0].size();
    vvi dp(xLen,vi(yLen,-1));
    for (int i = 0; i < xLen;i++){
        for (int j = 0; j < yLen;j++){
            if (i == 0 and j == 0){
                dp[0][0] = grid[0][0] ? 0:1;
            }
            else {
                int left = 0, down = 0;
                if (j > 0)
                    left = grid[i][j]?0:dp[i][j-1];
                if (i > 0)
                    down = grid[i][j]?0:dp[i-1][j];
                dp[i][j] = left + down; 
            }
        }
    }
    return dp[xLen-1][yLen-1];
} 
};
class Solution_space_opt {
public:
int f(vvi &grid){
    int xLen = grid.size(), yLen = grid[0].size();
    vi p(yLen),c(yLen);
    for (int i = 0; i < xLen;i++){
        for (int j = 0; j < yLen;j++){
            if  (i==0 and j==0) {
                c[0] = !grid[0][0];
                continue;
            }
            int left = 0, down = 0;
            if (j > 0) left = (!grid[i][j])*(c[j-1]);
            if (i > 0) down = (!grid[i][j])*(p[j]);
            c[j] = left + down;
        }
        p = c;
    }
    return c[yLen-1];
}
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        Solution_space_opt obj;
        // int xLen = obstacleGrid.size();
        // int yLen = obstacleGrid[0].size();
        // vvi dp(xLen,vi(yLen,-1));
        return obj.f(obstacleGrid);
    }
};
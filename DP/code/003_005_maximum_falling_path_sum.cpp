#include <vector>
#include <bits/stdc++.h>
using std::vector;
using std::max;
using std::max_element;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution_recursive {
public:
int f(int x,int y,vvi &matrix){
    if ( y < 0 or y >= matrix[0].size()) return -1e9;
    if (x < 0) return 0;
    int maxi = -1e9;
    for (int i = -1; i < 2; i++)
        maxi = max(maxi,matrix[x][y] + f(x-1,y-i,matrix));
    return maxi;
}
int fMain (vvi &matrix){
    int maxi = -1e9;
    for (int i = 0; i < matrix[0].size();i++)
        maxi = max(maxi,f(matrix.size()-1,i,matrix));
    return maxi;
}
};

class Solution_memo {
public:
int f(int x,int y,vvi &matrix,vvi &dp){
    if ( y < 0 or y >= matrix[0].size()) return -1e9;
    if (x < 0) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int maxi = -1e9;
    for (int i = -1; i < 2; i++)
        maxi = max(maxi,matrix[x][y] + f(x-1,y-i,matrix,dp));
    return dp[x][y] = maxi;   
}
int fMain (vvi &matrix){
    int xLen = matrix.size(), yLen = matrix[0].size();
    vvi dp(xLen,vi(yLen,-1));
    int maxi = -1e9;
    for (int i = 0; i < yLen;i++)
        maxi = max(maxi,f(xLen-1,i,matrix,dp));
    return maxi;
}
};

class Solution_tab {
public:
int f(vvi &matrix){
    int xLen = matrix.size(), yLen = matrix[0].size();
    vvi dp(xLen,vi(yLen));
    for (int j = 0; j < yLen;j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1;i < xLen;i++){
        for (int j = 0;j < yLen;j++){
            int down = dp[i-1][j];
            int left = j > 0?dp[i-1][j-1] :-1e9;
            int right = j < yLen -1?dp[i-1][j+1]:-1e9;
            dp[i][j] = matrix[i][j] + max(down,max(left,right)); 
        }
    }
    return *max_element(dp[xLen-1].begin(),dp[xLen-1].end());
}
};

class Solution_space_opt {
public:
int f(vvi &matrix){
    int xLen = matrix.size(), yLen = matrix[0].size();
    vi p(yLen), c(yLen);
    for (int j = 0;j < yLen;j++)
        p[j] = matrix[0][j];
    
    for (int i = 1;i < xLen;i++){
        for (int j = 0;j < yLen;j++){
            int down = p[j];
            int left = j > 0?p[j-1] :-1e9;
            int right = j < yLen -1?p[j+1]:-1e9;
            c[j] = matrix[i][j] + max(down,max(left,right));             
        }
        p = c;
    }
    return *max_element(p.begin(),p.end());
}
};

int getMaxPathSum(vector<vector<int>> &matrix){
    Solution_space_opt obj;
    return obj.f(matrix);
}
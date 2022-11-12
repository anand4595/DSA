#include <bits/stdc++.h> 
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution_recursive {
public:
int f(int x ,int y ,vvi &tri){
    if (x == tri.size()) return 0;
    return tri[x][y] + min(f(x+1,y,tri),f(x+1,y+1,tri));
}
};

class Solution_memo {
public:
int f(int x,int y,vvi &tri,vvi &dp){
    if (x == tri.size()) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = tri[x][y] + min(f(x+1,y,tri,dp),f(x+1,y+1,tri,dp));
}
};

class Solution_tab {
public:
int f(vvi &triangle){
    int n = triangle.size();
    vvi dp(n,vi(n));
    for (int j = 0; j < n;j++) 
    dp[n-1][j] = triangle[n-1][j];

    for (int i = n-2; i >= 0;i--){
        for (int j = 0; j <= i;j++){
            dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
};

class Solution_space_opt {
public:
int f(vvi &triangle){
    int n = triangle.size();
    vi p(n),c(n);
    for (int j = 0; j < n;j++)
    p[j] = triangle[n-1][j];
    for (int i = n-2; i >= 0;i--){
        for (int j = 0; j <= i;j++){
            c[j] = triangle[i][j] + min(p[j],p[j+1]);
        }
        p = c;
    }
    return p[0];
}
};

int minimumPathSum(vector<vector<int>>& triangle, int n){
	Solution_space_opt obj;
    // vvi dp(n,vi(n,-1));
    return obj.f(triangle);
}
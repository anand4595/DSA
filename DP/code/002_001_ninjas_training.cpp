#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class solution_recursive {
public:
int f(int n,int l,vvi &points){
    if (!n) return 0;
    int maxi = 0;
    for (int i = 0; i < 3;i++){
        if (l != i){
            int activity = points[n-1][i] + f(n-1,i,points);
            maxi = max(maxi,activity);
        } 
    }
    return maxi;
}
};

class Solution_memoization {
public:
int f(int n,int l,vvi &points,vvi &dp){
    if (!n) return 0;
    if (dp[n][l] != -1) return dp[n][l];
    int maxi = 0;
    for (int i = 0;i < 3;i++){
        if (l != i){
            int activity = points[n-1][i] + f(n-1,i,points,dp);
            maxi = max(maxi,activity);
        }
    }
    return dp[n][l] = maxi;
}
};

class Solution_tabulation {
public:
int f(int n,vvi &points){
    vvi dp(n,vi(3,-1));
    for (int i = 0; i < 3;i++)
        dp[0][i] = points[0][i];
    
    for (int i = 1; i < n;i++){
        for (int j = 0; j < 3;j++){
            int lz = j == 0? 0:dp[i-1][0];
            int lo = j == 1? 0:dp[i-1][1];
            int lt = j == 2? 0:dp[i-1][2];
            dp[i][j] = points[i][j] + max(lz,max(lo,lt));
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());
}
};

class Solution_space_opt {
public:
int f(int n,vvi &points){
    vi p(3), c(3);
    for (int i = 0;i < 3;i++)
        p[i] = points[0][i];
    
    for (int i = 1; i < n;i++){
        for (int j = 0; j < 3;j++){
            int lz = j == 0? 0:p[0];
            int lo = j == 1? 0:p[1];
            int lt = j == 2? 0:p[2];
            c[j] = points[i][j] + max(lz,max(lo,lt));            
        }
        p = c;
    }
    return *max_element(c.begin(),c.end());
}
};

int ninjaTraining(int n, vector<vector<int>> &points){
    Solution_space_opt a;
    // vvi dp(n+1,vi(4,-1));
    return a.f(n,points);
}
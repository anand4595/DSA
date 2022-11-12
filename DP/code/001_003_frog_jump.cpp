#include <bits/stdc++.h> 
using namespace std;

class Solution_rec {
public:
int f (int n, vector<int> &heights){
    if ( n == 0) return 0;
    int minus_2 = 1e9;
    if (n > 1)
        minus_2 =  abs(heights[n] - heights[n-2])+ f(n-2,heights);
    int minus_1 = abs(heights[n-1] - heights[n]) + f(n-1,heights);
    return min(minus_2,minus_1);
}
};

class Solution_memo {
public:
int f (int n, vector<int> &heights,vector<int> &dp){
    if ( n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int minus_2 = 1e9;
    if (n > 1)
        minus_2 =  abs(heights[n] - heights[n-2])+ f(n-2,heights,dp);
    int minus_1 = abs(heights[n-1] - heights[n]) + f(n-1,heights,dp);
    return dp[n] = min(minus_2,minus_1);
}
};

class Solution_tab {
public:
int f(int n,vector<int> &heights){
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1;i < n;i++){
        int minus_2 = 1e9;
        if (n>1) minus_2 = abs(heights[i] - heights[i-2]) + dp[i-2];
        int minus_1 = abs(heights[i]-heights[i-1]) + dp[i-1];
        dp[i] = min(minus_1,minus_2);
    }
    return dp[n-1];
}
};

int frogJump(int n, vector<int> &heights){
    Solution_tab obj;
    // vector<int> dp (n+1,-1);
    return obj.f(n,heights); 
}
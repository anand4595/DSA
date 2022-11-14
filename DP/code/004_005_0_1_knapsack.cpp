
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution_recusive {
public:
int f(int n,int w,int wt[],int val[]){
    if (!n or !w) return 0;
    int take = wt[n-1]<=w?val[n-1]+
    f(n-1,w-wt[n-1],wt,val):0;
    int not_take = f(n-1,w,wt,val);
    return max(take,not_take);
}
int fSolve(int n,int w,int wt[],int val[]){
    return f(n,w,wt,val);
}
};

class Solution_memo {
public:
int f(int n,int w,int wt[],int val[],vvi &dp){
    if (!n or !w) return 0;
    if (dp[n][w] != -1) return dp[n][w];
    int take = wt[n-1]<=w?val[n-1]+f(n-1,w-wt[n-1],wt,val,dp):0;
    int not_take = f(n-1,w,wt,val,dp);
    return dp[n][w] = max(take,not_take);
}
int fSolve (int n,int w,int wt[],int val[]){
    vvi dp(n+1,vi(w+1,-1));
    return f(n,w,wt,val,dp);
}
};

class Solution_tab {
public:
int f(int n,int w,int wt[],int val[]){
    vvi dp(n+1,vi(w+1));
    for (int i = 0; i < n+1;i++) dp[i][0] = 0;
    for (int j = 0; j < w+1;j++) dp[0][j] = 0; 
    
    for (int i=1;i<n+1;i++){
        for (int j=1;j<w+1;j++){
            int take = 
            wt[i-1]<=j?val[i-1]+dp[i-1][j-wt[i-1]]:0;
            int not_take = dp[i-1][j];
            dp[i][j] = max(take,not_take);
        }
    }
    return dp[n][w];
}
int fSolve (int n,int w,int wt[],int val[]){
    return f(n,w,wt,val);
}
};

class Solution_space_opt {
public:
int f(int n,int w,int wt[],int val[]){
    vi p(w+1),c(w+1);
    for (int j = 0; j < w+1;j++) p[j] = 0; 
    
    for (int i=1;i<n+1;i++){
        for (int j=1;j<w+1;j++){
            int take = 
            wt[i-1]<=j?val[i-1]+p[j-wt[i-1]]:0;
            int not_take = p[j];
            c[j] = max(take,not_take);
        }
        p = c;
    }
    return p[w];
}
int fSolve (int n,int w,int wt[],int val[]){
    return f(n,w,wt,val);
}
};

class Solution{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n){ 
       Solution_space_opt obj;
       return obj.fSolve(n,W,wt,val);
    }
};
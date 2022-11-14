#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution_rec {
public:
int f(int n,int w,int val[],int wt[]){
    if (!n || !w) return 0;
    int take = wt[n-1]<=w?val[n-1]+f(n,w-wt[n-1],val,wt):0;
    int not_take = f(n-1,w,val,wt);
    return max(take,not_take);
}
};
class Solution_memo {
public:
int f(int n,int w,int val[],int wt[],vvi &dp){
    if (!n || !w) return 0;
    if (dp[n][w] != -1) return dp[n][w];
    int take = wt[n-1]<=w?val[n-1]+f(n,w-wt[n-1],val,wt,dp):0;
    int not_take = f(n-1,w,val,wt,dp);
    return dp[n][w] = max(take,not_take);
}
int f_solve(int n,int w,int val[],int wt[]){
    vvi dp(n+1,vi(w+1,-1));
    return f(n,w,val,wt,dp);
}
};
class Solution_tab {
public:
int f(int n,int w,int val[],int wt[]){
    vvi dp(n+1,vi(w+1,0));
    for (int i = 1;i < n+1;i++){
        for (int j = 1;j < w+1;j++){
            int take = wt[i-1]<=j?
            val[i-1]+dp[i][j-wt[i-1]]:0;
            int not_take = dp[i-1][j];
            dp[i][j] = max(take,not_take);
        }
    }
    return dp[n][w];
}
};
class Solution_spa_opt {
public:
int f(int n,int w,int val[],int wt[]){
    vi c(w+1),p(w+1,0);
    for (int i = 1;i < n+1;i++){
        for (int j = 1;j < w+1;j++){
            int take = wt[i-1]<=j?
            val[i-1]+c[j-wt[i-1]]:0;
            int not_take = p[j];
            c[j] = max(take,not_take);
        }
        p = c;
    }
    return p[w];
}
};
class Solution{
public:
int knapSack(int N, int W, int val[], int wt[]){
    Solution_spa_opt obj;
    return obj.f(N,W,val,wt);
}
};
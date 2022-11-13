#include <vector>
#include <cmath>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int m = 1e9+7;

class Solution_rec {
public:
int f(int n,int s,int arr[],int cz[]){
    if (s == 0) return !n?1:pow(2,cz[n-1]);
    if (n == 0 or s < 0) return 0;
    int take = f(n-1,s-arr[n-1],arr,cz);
    int not_take = f(n-1,s,arr,cz);
    return (take+not_take)%m;
}
};

class Solution_memo {
public:
int f(int n,int s,int arr[],int cz[],vvi &dp){
    if (s == 0) return !n?1:pow(2,cz[n-1]);
    if (n == 0 or s < 0) return  0;
    if (dp[n][s] != -1) return dp[n][s];
    int take = f(n-1,s-arr[n-1],arr,cz,dp);
    int not_take = f(n-1,s,arr,cz,dp);
    return dp[n][s] = (take+not_take)%m;
}
};

class Solution_tab {
public:
int f(int arr[],int n,int sum){
    int dp[n+1][sum+1];
    int cz = 0;
    for (int i = 1; i < n+1;i++){
        if (arr[i-1] == 0) cz++;
        dp[i][0] = pow(2,cz);
    }
    for (int j = 1;j< sum+1;j++) dp[0][j] = 0;
    dp[0][0] = 1;
    for (int i = 1;i < n+1;i++){
        for (int j = 1;j < sum+1;j++){
            int take = arr[i-1]<=j?dp[i-1][j-arr[i-1]]:0;
            int not_take = dp[i-1][j];
            dp[i][j] = (take + not_take)%m;
        }
    }
    return dp[n][sum];
}
};

class Solution_spa_opt {
public:
int f(int arr[],int n,int sum){
    int cz[n+1];
    cz[0] = 1;
    int count = 0;
    for (int i = 1;i < n;i++){
        if (arr[i-1] == 0) count++;
        cz[i] = pow(2,count);
    }    
    vi p(sum+1),c(sum+1);
    for (int i = 0;i< sum+1;i++) p[i] = 0;
    for (int i = 1;i < n+1;i++){
        p[0] = cz[i-1];
        for (int j = 1;j < sum+1;j++){
            int take = arr[i-1]<=j?p[j-arr[i-1]]:0;
            int not_take = p[j];
            c[j] = (take + not_take)%m;
        }
        p = c;
    }
    return p[sum];
}
};

class Solution{
public:
int perfectSum(int arr[], int n, int sum){
    // int cz[n];
    // int c = 0;
    // for (int i = 0; i < n;i++){
        // if (arr[i] == 0) c++;
        // cz[i] = c;
    // }
    Solution_spa_opt obj;
    // vvi dp(n+1,vi(sum+1,-1));
    return obj.f(arr,n,sum);
}
};
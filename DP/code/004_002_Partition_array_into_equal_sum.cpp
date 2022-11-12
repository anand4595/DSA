#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution_recursive {
public:
int f(int n,int k,int arr[]){
    if (!k) return 1;
    if (!n or k < 0) return 0;
    int curr_element = arr[n-1];
    int take = curr_element <= k ? f(n-1,k - curr_element,arr) : 0;
    int not_take = f(n-1,k,arr);
    return take or not_take;
}
};

class Solution_memoization {
public:
int f(int n,int k,int arr[],vvi &dp){
    if (!k) return 1;
    if (!n or k < 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    int curr_ele = arr[n-1];
    int take = curr_ele <= k ? 
    f(n-1,k-curr_ele,arr,dp): 0;
    int not_take = f(n-1,k,arr,dp);
    return dp[n][k] = take or not_take;
}
};

class Solution_tabulation {
public:
bool f(int n,int arr[]){
    int sum = accumulate(arr,arr+n,0);
    if (sum%2) return false;
    sum /= 2;
    vvi dp(n+1,vi(sum+1));
    for (int i = 0; i < n + 1; i++) dp[i][0] = 1;
    for (int j = 1; j < sum + 1; j++) dp[0][j] = 0;

    for (int i = 1; i < n+1;i++){
        for (int j = 1;j < sum+1;j++){
            int curr_element = arr[i-1];
            int take = curr_element <= j? dp[i-1][j-curr_element]:0;
            int not_take = dp[i-1][j];
            dp[i][j] = take or not_take;
        }
    }
    return dp[n][sum];
}
};

class Solution_space_optimized {
    public:
bool f(int n,int arr[]){
    int sum = accumulate(arr,arr+n,0);
    if (sum%2) return false;
    sum /= 2;
    vi p(sum+1,0),c(sum+1);
    for (int i = 1; i < n+1; i++){
        p[0] = c[0] = 1;
        for (int j = 1; j < sum+1; j++){
            int curr_element = arr[i-1];
            int take = curr_element <= j?p[j-curr_element]:0;
            int not_take = p[j];
            c[j] = take or not_take;
        }
        p = c;
    }
    return c[sum];
}
};

class Solution{
public:
int equalPartition(int N, int arr[]){
    Solution_space_optimized a;
    return a.f(N,arr);
}
};
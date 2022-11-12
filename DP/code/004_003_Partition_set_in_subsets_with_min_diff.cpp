#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;

class Solution_recursive {
bool f(int n,int s, vi &arr){
    if (s == 0) return 1;
    if (n == 0) return 0;
    int take = arr[n-1] <= s? f(n-1,s-arr[n-1],arr): 0;
    int not_take = f(n-1,s,arr);
    return take or not_take;
}
public:
int fSolve(vi &arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    vi possibleSumArr(sum+1);
    for (int i = 0; i < sum + 1;i++){
        possibleSumArr[i] = f(n,i,arr);
    }
    int minDiff = INT32_MAX;
    for (int i = 0; i < sum + 1;i++){
        if (possibleSumArr[i]){
            int currDiff = abs(sum-2*i);
            minDiff = min(minDiff,currDiff);
        }
    }
    return minDiff;
}
};

class Solution_memo {
public:
bool f(int n,int s,vi &ar,vvi &dp){
    if (s == 0) return 1;
    if (n == 0) return 0;
    if (dp[n][s] != -1) return dp[n][s];
    int take = ar[n-1] <= s?f(n-1,s-ar[n-1],ar,dp):0;
    int not_take = f(n-1,s,ar,dp);
    return dp[n][s] = take or not_take;
}
int fSolve(vi &arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    vvi dp(n+1,vi(sum+1,-1));
    vi possibleSumArr(sum+1);
    for (int i = 0; i < sum + 1;i++){
        possibleSumArr[i] = f(n,i,arr,dp);
    }
    int minDiff = INT32_MAX;
    for (int i = 0; i < sum + 1;i++){
        if (possibleSumArr[i]){
            int currDiff = abs(sum-2*i);
            minDiff = min(minDiff,currDiff);
        }
    }
    return minDiff;
}
};

class Solution_tab {
public:
int f(vi &arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    vvb dp(n+1,vb(sum+1));
    for (int j = 1;j < sum+1;j++) dp[0][j] = 0;
    for (int i = 0;i < n+1;i++) dp[i][0] = 1;
    for (int i = 1; i < n+1;i++){
        for (int j = 1; j < sum+1;j++){
            bool take = arr[i-1] <= j?
            dp[i-1][j-arr[i-1]]:0;
            bool not_take = dp[i-1][j];
            dp[i][j] = take or not_take;
        }
    }
    int minDiff = INT32_MAX;
    for (int j = 0; j < sum +1;j++){
        if (dp[n][j]) 
        minDiff = min(minDiff,abs(sum-2*j));
    }
    return minDiff;
}
};

class Solution_space_opt {
public:
int f(vi &arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    vb p(sum+1,0),c(sum+1);
    for (int i=1;i<n+1;i++){
        p[0] = c[0] = 1;
        for (int j=1;j<sum+1;j++){
            int take = arr[i-1]<=j?p[j-arr[i-1]]:0;
            int not_take = p[j];
            c[j] = take or not_take;
        }
        p = c;
    }
    int minDiff = INT32_MAX;
    for (int i=0;i<sum+1;i++){
        if(p[i]) minDiff = min(minDiff,abs(sum-2*i));
    }
    return minDiff;
}
};

int minSubsetSumDifference(vector<int>& arr, int n){
    Solution_space_opt obj;
    return obj.f(arr);
}
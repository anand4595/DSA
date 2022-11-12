#include <iostream>
#include <vector> 
using namespace std;

class solution_recursive {
    public:
    bool f(int n, int k,vector<int> &arr){
        if (k == 0) return 1;
        if (n == 0) return 0;
        int curr_element = arr[n-1];
        int take = 0;
        if (curr_element <= k) take = f(n-1,k-curr_element,arr);
        int not_take = f(n-1,k,arr);
        return take or not_take;
    }
};
class Solution_memo {
    public:
    using vi = vector<int>;
    using vvi = vector<vi>;
    bool f(int n,int k,vi &arr,vvi &dp){
        if (k == 0) return 1;
        if (n == 0 or k < 0) return 0;
        if (dp[n][k] != -1) return dp[n][k];
        int curr_element = arr[n-1];
        int take = f(n-1,k-curr_element,arr,dp);
        int not_take = f(n-1,k,arr,dp);
        return dp[n][k] = take or not_take;
    }
};
class Solution_tab {
    using vi = vector<int>;
    using vvi = vector<vi>;
    public:
    /**
     * Tabulation solution of subset sum equal to target 
     * @param n length of vector 
     * @param k target sum 
     * @param arr vectors address
     * @returns 0/1 depending if we got a subset equal to target  
    */
    bool f(int n,int k,vi &arr){
        vvi dp(n+1,vi(k+1,-1));
        for  (int i = 0; i < dp.size();i++) dp[i][0] = 1;
        for  (int j = 1; j < dp[0].size();j++) dp[0][j] = 0;
        for (int i = 1; i < n+1;i++){
            for (int j = 1; j < k + 1;j++){
                int not_take = dp[i-1][j];
                int curr_ele = arr[i-1];
                int take = curr_ele <= j ? dp[i-1][j-curr_ele]:0;
                dp[i][j] = take or not_take;
            }
        }
        return dp[n][k];
    }
};
class Solution_space_optimized {
    using vi = vector<int>;
    public:
    bool f(int n,int k,vi &arr){
        vi c(k+1),p(k+1,0);
        p[0] = c[0] = 1;
        for (int i = 1; i < n+1;i++){
            c[0] = 1;
            for (int j = 1; j < k+1;j++){
                int curr_element = arr[i-1];
                int take = curr_element <= j? p[j-curr_element]:0;
                int not_take = p[j];
                c[j] = take or not_take;
            }
            p = c;
        }
        return c[k];
    }
};
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Solution_memo obj;
    Solution_space_optimized a;
    return a.f(n,k,arr);
}

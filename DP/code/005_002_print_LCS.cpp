#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution_tab {
public:
vvi get_lcs_dp(int n,int m,vi &a,vi &b){
    vvi dp(n+1,vi(m+1,0));
    for (int i = 1;i < n+1;i++){
        for (int j = 1;j < m+1;j++){
            if (a[i-1]==b[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp;
}
vi f_solver(vi &a,vi &b){
    int n = a.size();
    int m = b.size();
    vvi dp = get_lcs_dp(n,m,a,b);
    vi ans;
    while (n && m){
        if (a[n-1] == b[m-1]){
            ans.push_back(a[n-1]);
            --n;
            --m;
        }
        else if (dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
};

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    Solution_tab obj;
    return obj.f_solver(a,b);
}
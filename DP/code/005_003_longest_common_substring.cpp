#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution_tab {
public:
int f(string a,string b){
    int n = a.size();
    int m = b.size();
    vvi dp(n+1,vi(m+1,0));
    for (int i=1;i<n+1;i++){
        for (int j=1;j<m+1;j++){
            if (a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = 0;
        }
    }
    int maxi = 0;
    for (vi row : dp)
        maxi = max(maxi,*max_element(row.begin(),row.end()));
    return maxi;
}
int f_solve(string a,string b){
    return f(a,b);
}
};

class Solution{
public:
int longestCommonSubstr (string S1, string S2, int n, int m){
    Solution_tab obj;
    return obj.f_solve(S1,S2);
}
};
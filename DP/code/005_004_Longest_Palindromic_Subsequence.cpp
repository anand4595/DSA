#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution_rec {
public:
int f(int n,int m,string a,string b){
    if (!n || !m) return 0;
    if (a[n-1] == b[m-1])
        return 1+f(n-1,m-1,a,b);
    return max(f(n-1,m,a,b),f(n,m-1,a,b));
}
int f_solve(string s){
    string s1 = s;
    reverse(s1.begin(),s1.end());
    return f(s.size(),s.size(),s,s1);
}
};

class Solution_memo {
public:
int f(int n,int m,string a,string b,vvi dp){
    if (!n || !m) return 0;
    if (dp[n][m] != -1) dp[n][m];
    if (a[n-1] == b[m-1])
        return dp[n][m] = 1+f(n-1,m-1,a,b,dp);
    return dp[n][m] = max(f(n-1,m,a,b,dp),f(n,m-1,a,b,dp));
}
int f_solve(string s){
    string s1 = s;
    reverse(s1.begin(),s1.end());
    vvi dp(s.size()+1,vi(s.size()+1,-1));
    return f(s.size(),s.size(),s,s1,dp);
}
};

class Solution_tab {
public:
int f(string a){
    string b = a;
    reverse(b.begin(),b.end());
    int n = a.size(),m = a.size();
    vvi dp(n+1,vi(n+1,0));
    for (int i=1;i<n+1;i++){
        for (int j=1;j<m+1;j++){
            if (a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
};

class Solution_spa_opt {
public:
int f(string a){
    string b = a;
    reverse(b.begin(),b.end());
    int n = a.size(),m = a.size();
    vi p(n+1,0),c(n+1,0);
    for (int i=1;i<n+1;i++){
        for (int j=1;j<m+1;j++){
            if (a[i-1]==b[j-1])
                c[j] = 1+p[j-1];
            else 
                c[j] = max(p[j],c[j-1]);
        }
        p = c;
    }
    return p[n];
}
};

class Solution{
public:
int longestPalinSubseq(string A) {
    Solution_spa_opt obj;
    return obj.f(A);
}
};
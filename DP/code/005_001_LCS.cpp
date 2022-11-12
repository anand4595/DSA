#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>; 

class Solution_rec {
public:
int f(int x,int y,string s1,string s2){
    if (!x or !y) return 0;
    if (s1[x-1] == s2[y-1]) return 1+f(x-1,y-1,s1,s2);
    return max(f(x-1,y,s1,s2),f(x,y-1,s1,s2));
}
};

class Solution_memo {
public:
int f(int x,int y,string s1,string s2,vvi &dp){
    if (!x or !y) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    if (s1[x-1] == s2[y-1]) 
        return dp[x][y] = 1+f(x-1,y-1,s1,s2,dp);
    return dp[x][y] = max(f(x-1,y,s1,s2,dp),f(x,y-1,s1,s2,dp));
}
};

class Solution_tab {
public:
int f(int x,int y,string s1,string s2){
    vvi dp(x+1,vi(y+1,0));
    for (int i=1;i<x+1;i++){
        for (int j=1;j<y+1;j++){
            if (s1[i-1] == s2[j-1])
                dp[i]
                
                [j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y];
}

};

class Solution_space_opt {
public:
int f(int x,int y,string s1,string s2){
    vi p(y+1,0),c(y+1);
    for (int i=1;i<x+1;i++){
        c[0] = p[0] = 0;
        for (int j=1;j<y+1;j++){
            if (s1[i-1] == s2[j-1])
                c[j] = 1 + p[j-1];
            else 
                c[j] = max(p[j],c[j-1]);
        }
        p = c;
    }
    return p[y];
}
};

class Solution{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        Solution_space_opt obj;
        vvi dp(x+1,vi(y+1,-1));
        return obj.f(x,y,s1,s2);
    }
};
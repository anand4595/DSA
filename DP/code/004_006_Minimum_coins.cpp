#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

using vvi = vector<vi>;

class Solution_rec {
public:
int f(int n,int x,vi &num){
    if (x==0) return 0;
    if (n==0) return 1e9;
    int take = num[n-1]<=x ? 1+f(n,x-num[n-1],num):1e9;
    int not_take = f(n-1,x,num);
    return min(take,not_take);
}
int minimumElements(vector<int> &num, int x){
    int ans = f(num.size(),x,num);
    return ans >= 1e9?-1:ans;
}
};

class Solution_memo {
public:
int f(int n,int x,vi &num,vvi &dp){
    if (x==0) return 0;
    if (n==0) return 1e9;
    if (dp[n][x] != -1) return dp[n][x];
    int take = num[n-1]<=x?1+f(n,x-num[n-1],num,dp):1e9;
    int not_take = f(n-1,x,num,dp);
    return dp[n][x] = min(take,not_take);
}
int minimumElements(vector<int> &num, int x){
    vvi dp(num.size()+1,vi(x+1,-1));
    int ans = f(num.size(),x,num,dp);
    return ans >= 1e9?-1:ans;
}
};


class Solution_tab {
public:
int f(vector<int> &num,int t){
    int nS = num.size();
    vvi dp(nS+1,vi(t+1));
    for (int n = 0; n < nS+1;n++){
        for (int x = 0;x < t+1;x++){
            if (x==0) dp[n][x] = 0;
            else if (n==0) dp[n][x] = 1e9;
            else {
            int take = num[n-1]<=x ? 1 + dp[n][x-num[n-1]]:1e9;
            int not_take = dp[n-1][x];
            dp[n][x] = min(take,not_take);
            }
        }
    }
    int ans = dp[nS][t];
    return ans >= 1e9?-1:ans;
}
int minimumElements(vector<int> &num, int x){
    int ans = f(num,x);
    return ans >= 1e9?-1:ans;
}
};

class Solution_space_opt {
public:
int f(vector<int> &num,int t){
    int nS = num.size();
    vi p(t+1),c(t+1);
    for (int n = 0; n < nS+1;n++){
        for (int x = 0;x < t+1;x++){
            if (x==0) c[x] = 0;
            else if (n==0) c[x] = 1e9;
            else {
            int take = num[n-1]<=x ? 1 + c[x-num[n-1]]:1e9;
            int not_take = p[x];
            c[x] = min(take,not_take);
            }
        }
        p = c;
    }
    int ans = p[t];
    if (ans >= 1e8) return -1;
    return ans;
}
};

int minimumElements(vector<int> &num, int x){
    Solution_space_opt obj;
    return obj.f(num,x);
}
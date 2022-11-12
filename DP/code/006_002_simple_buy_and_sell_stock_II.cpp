#include <iostream>
#include <vector>
using namespace std;
using vl = vector<long>;
using vvl = vector<vl>;

class Solution_rec {
public:
long f(int n,int b,vl &values){
    if (n == values.size()) return 0;
    // not bought 
    long profit = 0;
    if (b == 0){
        long buy = -values[n] + f(n+1,1,values);
        long not_buy = f(n+1,0,values);
        profit = max(buy,not_buy);
    }
    else {
        long sell = values[n] + f(n+1,0,values);
        long not_sell = f(n+1,1,values);
        profit = max(sell,not_sell);
    }
    return profit;
}
};

class Solution_memo {
public:
long f(int n,int b,vl &values,vvl &dp){
    if (n == values.size()) return 0;
    if (dp[n][b] != -1) return dp[n][b];

    // not bought 
    long profit = 0;
    if (b == 0){
        long buy = -values[n] + f(n+1,1,values,dp);
        long not_buy = f(n+1,0,values,dp);
        profit = max(buy,not_buy);
    }
    else {
        long sell = values[n] + f(n+1,0,values,dp);
        long not_sell = f(n+1,1,values,dp);
        profit = max(sell,not_sell);
    }
    return dp[n][b] = profit;
}
};

class Solution_tab {
public:
long f(int n,vl &values){
    vvl dp(n+1,vl(2,0));
    for (int i=n-1;i>=0;i--){
        for (int b=0;b<=1;b++){
            long profit = 0;
            if (b==0){
                long buy = -values[i] + dp[i+1][1];
                long not_buy = dp[i+1][0];
                profit = max(buy,not_buy);
            }
            else {
                long sell = values[i] + dp[i+1][0];
                long not_sell = dp[i+1][1];
                profit = max(sell,not_sell);
            }
            dp[i][b] = profit;
        }
    }
            return dp[0][0];
}
};

class Solution_space_opt {
public:
int f(int n,vl &values){
    vl p(2,0),c(2);
    for 
}
};

vl atov (long *a,int n){
    vl v(n);
    for (int i = 0;i<n;i++)
        v[i] = a[i];
    return v; 
}
long getMaximumProfit(long *values, int n){
    Solution_tab obj;
    vl v = atov(values,n);
//     vvl dp(n+1,vl(2,-1));
    return obj.f(n,v);
}
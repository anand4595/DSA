#include <bits/stdc++.h>
using namespace std;


using li = long long int;
using vli = vector<li>;
using vvli = vector<vli>;

class Solution_rec {
public:
li f(int n,int s,int coins[]){
    if (s==0) return 1;
    if (n==0) return 0;
    li take = coins[n-1]<=s?f(n,s-coins[n-1],coins):0;
    li not_take = f(n-1,s,coins);
    return take + not_take;
}
li fSolve (int coins[],int n,int s){
    return f(n,s,coins);
}
};

class Solution_memo {
public:
li f(int n,int s,int coins[],vvli &dp){
    if (s==0) return 1;
    if (n==0) return 0;
    if (dp[n][s] != -1) return dp[n][s];
    li take = coins[n-1]<=s?f(n,s-coins[n-1],coins,dp):0;
    li not_take = f(n-1,s,coins,dp);
    return dp[n][s] = take + not_take;
}
li fSolve (int coins[],int n,int s){
    vvli dp(n+1,vli(s+1,-1));
    return f(n,s,coins,dp);
}
};



class Solution {
public:
long long int count(int coins[], int N, int sum) {
    Solution_memo obj;
    return obj.fSolve(coins,N,sum);
}
};
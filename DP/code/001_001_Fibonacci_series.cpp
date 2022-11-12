#include <vector>
using std::vector;

using li = long long int;
using vi = vector<li>;
long long int m = 1000000007;

class Solution_rec {
public:
li f(li n){
    if (n <= 1) return n;
    return (f(n-1)%m+ f(n-2)%m)%m;
}
};

class Solution_memo {
public:
li f(li n,vi &dp){
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return (f(n-1,dp)%m + f(n-2,dp)%m)%m;
}
};

class Solution_tab {
public:
li f(li n){
    vi dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2;i<n+1;i++)
        dp[i] = (dp[i-1] + dp[i-2])%m;
    return dp[n];
}
};

class Solution_space_opt {
public:
li f(li n){
    li p = 0;
    li c = 1;
    li nth = 1;
    for (int i = 2;i<n+1;i++){
        nth = (p + c)%m;
        p = c;
        c = nth;
    }
    return nth;
}
};

class Solution {
public:
long long int nthFibonacci(long long int n){
    Solution_space_opt obj;
    // vi dp(n+1,-1);
    return obj.f(n);
}
};
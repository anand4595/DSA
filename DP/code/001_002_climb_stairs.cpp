#include <vector>
using std::vector;
using vi = vector<int>;

int m = 1000000007;
class Solution_rec {
public:
int f(int n){
    if (n <= 1) return n;
    return (f(n-1) + f(n-2))%m;
}
};

class Solution_memo {
public:
int f(int n,vi &dp){
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = (f(n-1,dp) + f(n-2,dp))%m; 
}
};

class Solution_tab {
public:
int f(int n){
    vi dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2;i < n+1;i++)
        dp[i] = (dp[i-1] + dp[i-2])%m;
    return dp[n];
}
};

class Solution_space_opt {
public:
int f(int n){
    int p = 0,c = 1;
    int a = p+c;
    for (int i = 2;i <= n;i++){
        a = (p+c)%m;
        p = c;
        c = a;
    }
    return a;
}
};

int countDistinctWays(int n) {
    Solution_tab obj;
    // vi dp(n+2,-1);
    return obj.f(n+1);
}
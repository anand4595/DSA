#include <vector>
using std::max;
using std::vector;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution_rec {

public:
int f(int l,int n,int price[]){
    if (n==0 or l==0) return 0;
    int take = n<=l?price[n-1] + f(l-n,n,price):0;
    int not_take = f(l,n-1,price);
    return max(take,not_take);
}

};

class Solution_memo {
public:
int f(int l,int n,int price[],vvi &dp){
    if (n==0 or l==0) return 0;
    if (dp[l][n] != -1) return dp[l][n];
    int take = n<=l?price[n-1] + f(l-n,n,price,dp):0;
    int not_take = f(l,n-1,price,dp);
    return dp[l][n] = max(take,not_take);
}

};

class Solution_tab {
public:
int f(int price[],int n){
    int l = n;
    vvi dp(n+1,vi(l+1,0));
    for (int i=1;i<n+1;i++){
        for (int j=1;j<l+1;j++){
            int take = i<=j? price[i-1]+dp[i][j-i]:0;
            int not_take = dp[i-1][j];
            dp[i][j] = max(take,not_take);
        }
    }
    return dp[n][l];
}
};

class Solution_space_opt {
public:
int f(int price[],int n){
    int l = n;
    vi p(l+1,0),c(l+1);
    for (int i=1;i<n+1;i++){
        c[0] = p[0] = 0;
        for (int j=1;j<l+1;j++){
            int take = i<=j? price[i-1]+c[j-i]:0;
            int not_take = p[j];
            c[j] = max(take,not_take);
        }
        p = c;
    }
    return p[l];
}

};

class Solution{
  public:
    int cutRod(int price[], int n) {
        Solution_space_opt obj;
        // vvi dp(n+1,vi(n+1,-1));
        return obj.f(price,n);
    }
};
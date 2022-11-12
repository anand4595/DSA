#include <vector>
using std::vector;
using vi = vector<int>;
using vvi = vector<vi>;
class Solution_recursive {
public:
int f(int a,int b){
    if (!a && !b) return 1;
    if (a < 0 or b < 0) return 0;
    return f(a-1,b) + f(a,b-1);
}
};

class Solution_memo {
public:
int f(int a,int b,vvi &dp){
    if (!a && !b) return 1;
    if (a < 0 || b < 0) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    return dp[a][b] = f(a-1,b,dp) + f(a,b-1,dp);
}
};

class Solution_tab {
public:
int f(int a,int b){
    vvi dp(a,vi(b));
    for(int j = 0; j < b; j++) dp[0][j] = 1;
    for (int i = 0; i < a; i++) dp[i][0] = 1;

    for (int i = 1; i < a; i++){
        for (int j = 1; j < b;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[a-1][b-1];
}
};

class Solution_space_opt {
public:
int f(int a,int b){
    vi p(b,1), c(b,1);
    for (int i = 1; i < a; i++){
        for (int j = 1;j < b;j++){
            c[j] = p[j] + c[j-1];
        }
        p = c;
    }
    return c[b-1];
}
};

class Solution{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b){
        Solution_space_opt obj;
        return obj.f(a,b);
    }
};
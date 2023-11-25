// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// leetcode post TBD
package DynamicProgramming._01_knapsackPattern._01_knapsackStandard;

class Solve {
  // recursive
  public int solveRecursive(int W, int[] wt, int[] val, int n) {
    // base case
    if (W == 0 || n < 0)
      return 0;
    int currWeight = wt[n];
    int currValue = val[n];
    int takeValue = 0;
    if (currWeight <= W)
      takeValue = currValue + solveRecursive(W - currWeight, wt, val, n - 1);
    int notTakeVakue = solveRecursive(W, wt, val, n - 1);
    return Integer.max(takeValue, notTakeVakue);
  }

  // memoization
  public int solveMemoization(int w, int n, int[] wt, int[] val) {
    int[][] dp = new int[w + 1][n + 1];
    for (int i = 0; i < w + 1; i++) {
      for (int j = 0; j < n + 1; j++)
        dp[i][j] = -1;
    }
    return solveMemoization(w, n, dp, wt, val);
  }

  public int solveMemoization(int w, int n, int[][] dp, int[] wt, int[] val) {
    if (w <= 0 || n == 0)
      return 0;
    int currWeight = wt[n - 1];
    int currValue = val[n - 1];
    int takeValue = 0;
    if (dp[w][n] != -1)
      return dp[w][n];
    if (currWeight <= w)
      takeValue = currValue + solveMemoization(w - currWeight, n - 1, dp, wt, val);
    int notTakeVakue = solveMemoization(w, n - 1, dp, wt, val);
    return dp[w][n] = Integer.max(takeValue, notTakeVakue);
  }

  // tabulation
  public int solveTabulation(int w, int n, int[] wt, int[] val) {
    int[][] dp = new int[n + 1][w + 1];

    for (int i = 0; i < w + 1; i++)
      for (int j = 0; j < n + 1; j++)
        if (i == 0 || j == 0)
          dp[j][i] = 0;

    for (int idx = 1; idx < n + 1; idx++)
      for (int weight = 1; weight < w + 1; weight++) {
        int currValue = val[idx - 1];
        int currWeight = wt[idx - 1];
        int take = 0;
        if (currWeight <= weight)
          take = currValue + dp[idx - 1][weight - currWeight];
        int notTake = dp[idx - 1][weight];
        dp[idx][weight] = Integer.max(take, notTake);
      }

    return dp[n][w];
  }

  // sapceOptmized
  public int solveSapceOptmized(int w, int n, int wt[], int val[]) {
    int[] prev = new int[w + 1];
    int[] curr = new int[w + 1];
    prev[0] = 0;
    curr[0] = 0;

    for (int idx = 1; idx < n + 1; idx++) {
      for (int i = 0; i < w + 1; i++)
        prev[i] = curr[i];

      for (int weight = 1; weight < w + 1; weight++) {
        int currValue = val[idx - 1];
        int currWeight = wt[idx - 1];
        int take = 0;
        if (currWeight <= weight)
          take = currValue + prev[weight - currWeight];
        int notTake = prev[weight];
        curr[weight] = Integer.max(take, notTake);
      }
    }
    return curr[w];
  }

}

class Solution {
  // Function to return max value that can be put in knapsack of capacity W.
  static int knapSack(int W, int wt[], int val[], int n) {
    return new Solve().solveSapceOptmized(W, n, wt, val);
  }
}
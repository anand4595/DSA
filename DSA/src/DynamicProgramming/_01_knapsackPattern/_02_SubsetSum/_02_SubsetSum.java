// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// leetcode post TBD
package DynamicProgramming._01_knapsackPattern._02_SubsetSum;

class Solve {
  // recursive
  public Boolean solveRecursive(int N, int arr[], int sum) {
    // base case
    if (sum == 0)
      return true;
    if (N == 0)
      return false;
    // main case
    int currNum = arr[N - 1];
    Boolean take = currNum <= sum ? solveRecursive(N - 1, arr, sum - currNum) : false;
    Boolean notTake = solveRecursive(N - 1, arr, sum);
    return take || notTake;
  }

  // memoization
  public Boolean solveMemoization(int N, int[] arr, int sum) {
    int[][] dp = new int[N + 1][sum + 1];
    for (int i = 0; i < N + 1; i++)
      for (int j = 0; j < sum + 1; j++)
        dp[i][j] = -1;

    return solveMemoization(N, sum, dp, arr) == 1 ? true : false;
  }

  public int solveMemoization(int N, int sum, int[][] dp, int[] arr) {
    // base case
    if (sum == 0)
      return 1;
    if (N == 0)
      return 0;
    if (dp[N][sum] != -1)
      return dp[N][sum];
    // main case
    int currNum = arr[N - 1];
    int take = currNum <= sum ? solveMemoization(N - 1, sum - currNum, dp, arr) : 0;
    int notTake = solveMemoization(N - 1, sum, dp, arr);
    return dp[N][sum] = take == 1 || notTake == 1 ? 1 : 0;
  }

  // tabulation
  public Boolean solveTabulation(int N, int arr[], int sum) {
    int[][] dp = new int[N + 1][sum + 1];
    // dp array initialization
    for (int i = 0; i < sum + 1; i++)
      dp[0][i] = 0;
    for (int i = 0; i < N + 1; i++)
      dp[i][0] = 1;
    // main code
    for (int idx = 1; idx < N + 1; idx++)
      for (int currSum = 1; currSum < sum + 1; currSum++) {
        int currNum = arr[idx - 1];
        int take = currNum <= currSum ? dp[idx - 1][currSum - currNum] : 0;
        int notTake = dp[idx - 1][currSum];
        dp[idx][currSum] = take == 1 || notTake == 1 ? 1 : 0;
      }
    return dp[N][sum] == 1 ? true : false;
  }

  // sapceOptmized
  public Boolean solveSapceOptmized(int N, int arr[], int sum) {
    // dp array initialization
    int[] prev = new int[sum + 1];
    int[] curr = new int[sum + 1];
    // main code
    for (int idx = 1; idx < N + 1; idx++) {
      curr[0] = 1;
      for (int i = 0; i < sum + 1; i++)
        prev[i] = curr[i];

      for (int currSum = 1; currSum < sum + 1; currSum++) {
        int currNum = arr[idx - 1];
        int take = currNum <= currSum ? prev[currSum - currNum] : 0;
        int notTake = prev[currSum];
        curr[currSum] = take == 1 || notTake == 1 ? 1 : 0;
      }
    }
    return curr[sum] == 1 ? true : false;
  }
}

class Solution {
  static Boolean isSubsetSum(int N, int arr[], int sum) {
    return new Solve().solveSapceOptmized(N, arr, sum);
  }
}
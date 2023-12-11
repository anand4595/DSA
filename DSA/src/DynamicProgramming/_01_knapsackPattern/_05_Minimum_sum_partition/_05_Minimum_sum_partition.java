// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// leetcode post TBD 
// TC - SC TBA
package DynamicProgramming._01_knapsackPattern._05_Minimum_sum_partition;

class Solve {
  // recursive
  public int solveRecursive(int arr[], int n) {
    int sum = 0;
    for (int i : arr)
      sum += i;
    int halfSum = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;
    Boolean[] subsetSumPossible = new Boolean[halfSum + 1];
    for (int i = 0; i < halfSum + 1; i++) {
      subsetSumPossible[i] = solveRecursive(n, i, arr);
    }
    int minSum = Integer.MAX_VALUE;
    for (int i = 0; i < halfSum + 1; i++) {
      if (subsetSumPossible[i])
        minSum = Integer.min(minSum, Math.abs(sum - 2 * i));
    }
    return minSum;
  }

  public Boolean solveRecursive(int length, int sum, int arr[]) {
    // error case
    if (sum < 0 || length < 0)
      throw new ArithmeticException("Sum or length can't be negative");
    // base case
    if (length == 0 || sum == 0)
      return sum == 0 ? true : false;
    // main code
    int currElement = arr[length - 1];
    Boolean takeCurrElement = currElement <= sum ? solveRecursive(length - 1, sum - currElement, arr) : false;
    Boolean notTakeCurrElement = solveRecursive(length - 1, sum, arr);
    return takeCurrElement || notTakeCurrElement;
  }

  // memoization
  public int solveMemoization(int arr[], int n) {
    int sum = 0;
    for (int i : arr)
      sum += i;
    int halfSum = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;

    Boolean[] subsetSumPossible = new Boolean[halfSum + 1];

    int[][] dp = new int[n + 1][halfSum + 1];
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < halfSum + 1; j++)
        dp[i][j] = -1;

    for (int i = 0; i < halfSum + 1; i++) {
      subsetSumPossible[i] = solveMemoization(n, i, dp, arr);
    }
    int minSum = Integer.MAX_VALUE;

    for (int i = 0; i < halfSum + 1; i++) {
      if (subsetSumPossible[i])
        minSum = Integer.min(minSum, Math.abs(sum - 2 * i));
    }

    return minSum;
  }

  public Boolean solveMemoization(int length, int sum, int[][] dp, int arr[]) {
    // error case
    if (sum < 0 || length < 0)
      throw new ArithmeticException("Sum or length can't be negative");
    // base case
    if (length == 0 || sum == 0)
      return sum == 0 ? true : false;
    if (dp[length][sum] != -1)
      return dp[length][sum] == 0 ? false : true;
    // main code
    int currElement = arr[length - 1];
    Boolean takeCurrElement = currElement <= sum ? solveMemoization(length - 1, sum - currElement, dp, arr) : false;
    Boolean notTakeCurrElement = solveMemoization(length - 1, sum, dp, arr);
    dp[length][sum] = takeCurrElement || notTakeCurrElement ? 1 : 0;
    return takeCurrElement || notTakeCurrElement;
  }

  // tabulation
  public int solveTabulation(int[] arr, int n) {
    int sum = 0;

    for (int i : arr)
      sum += i;
    int halfSum = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;

    boolean[][] dp = new boolean[n + 1][halfSum + 1];
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < halfSum + 1; j++)
        dp[i][j] = j == 0 ? true : false;

    for (int currLen = 1; currLen < n + 1; currLen++)
      for (int currSum = 1; currSum < halfSum + 1; currSum++) {
        int currNum = arr[currLen - 1];
        boolean take = currNum <= currSum ? dp[currLen - 1][currSum - currNum] : false;
        boolean notTake = dp[currLen - 1][currSum];
        dp[currLen][currSum] = take || notTake;
      }

    int minSum = Integer.MAX_VALUE;
    for (int i = 0; i < halfSum + 1; i++) {
      if (dp[n][i])
        minSum = Integer.min(minSum, Math.abs(sum - 2 * i));
    }
    return minSum;
  }

  // sapceOptmized
  public int solveSapceOptmized(int[] arr, int n) {
    int sum = 0;

    for (int i : arr)
      sum += i;
    int halfSum = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;

    boolean[] prev = new boolean[halfSum + 1];
    boolean[] curr = new boolean[halfSum + 1];

    for (int currLen = 1; currLen < n + 1; currLen++) {
      curr[0] = true;
      for (int i = 0; i < halfSum + 1; i++)
        prev[i] = curr[i];

      for (int currSum = 1; currSum < halfSum + 1; currSum++) {
        int currNum = arr[currLen - 1];
        boolean take = currNum <= currSum ? prev[currSum - currNum] : false;
        boolean notTake = prev[currSum];
        curr[currSum] = take || notTake;
      }
    }

    int minSum = Integer.MAX_VALUE;
    for (int i = 0; i < halfSum + 1; i++) {
      if (curr[i])
        minSum = Integer.min(minSum, Math.abs(sum - 2 * i));
    }
    return minSum;
  }

}

class Solution {

  public int minDifference(int arr[], int n) {
    return new Solve().solveSapceOptmized(arr, n);
  }
}
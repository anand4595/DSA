// https://leetcode.com/problems/partition-equal-subset-sum/
package DynamicProgramming._01_knapsackPattern._03_PartitionEqualSubsetSum;

class Solve {
  // recursive
  // TC - O(2^n)
  // SC - O(n)
  public Boolean solveRecursive(int[] nums) {
    int sum = 0;
    for (int i : nums)
      sum += i;
    if (sum % 2 == 1)
      return false;
    return solveRecursive(nums.length, sum / 2, nums);
  }

  public Boolean solveRecursive(int N, int sum, int[] nums) {
    // base case
    if (N == 0 || sum == 0)
      return sum == 0 ? true : false;
    // main case
    int currNum = nums[N - 1];
    Boolean take = currNum <= sum ? solveRecursive(N - 1, sum - currNum, nums) : false;
    Boolean notTake = solveRecursive(N - 1, sum, nums);
    return take || notTake;
  }

  // memoization
  // calling other function for memoization using function overloading
  // TC - O(n^2)
  // SC - O(n + n^2)
  public Boolean solveMemoization(int[] nums) {
    int sum = 0;
    for (int i : nums)
      sum += i;

    if (sum % 2 == 1)
      return false;
    int N = nums.length;

    int[][] dp = new int[N + 1][(sum / 2) + 1];

    for (int i = 0; i < N + 1; i++)
      for (int j = 0; j < (sum / 2) + 1; j++)
        dp[i][j] = -1;

    return solveMemoization(N, sum / 2, dp, nums) == 1 ? true : false;
  }

  public int solveMemoization(int N, int sum, int[][] dp, int[] nums) {
    // base case
    if (N == 0 || sum == 0)
      return sum == 0 ? 1 : 0;
    // dp
    if (dp[N][sum] != -1)
      return dp[N][sum];
    // main case
    int currNum = nums[N - 1];
    int take = currNum <= sum ? solveMemoization(N - 1, sum - currNum, dp, nums) : 0;
    int notTake = solveMemoization(N - 1, sum, dp, nums);
    return dp[N][sum] = take == 1 || notTake == 1 ? 1 : 0;
  }

  // tabulation
  // TC - O(n^2)
  // SC - O(n^2)
  public Boolean solveTabulation(int[] nums) {
    int N = nums.length;
    int sum = 0;
    for (int i : nums)
      sum += i;
    if (sum % 2 == 1)
      return false;
    boolean[][] dp = new boolean[N + 1][(sum / 2) + 1];
    // initializing dp array
    for (int i = 0; i < N + 1; i++)
      dp[i][0] = true;
    // main code
    for (int currLength = 1; currLength < N + 1; currLength++) {
      for (int currSum = 1; currSum < (sum / 2) + 1; currSum++) {
        int currNum = nums[currLength - 1];
        boolean take = currNum <= currSum ? dp[currLength - 1][currSum - currNum] : false;
        boolean notTake = dp[currLength - 1][currSum];
        dp[currLength][currSum] = take || notTake;
      }
    }
    return dp[N][(sum / 2)];
  }

  // sapceOptmized
  // TC - O(n^2)
  // Sc - O(sum)
  public Boolean solveSapceOptmized(int[] nums) {
    int N = nums.length;
    int sum = 0;
    for (int i : nums)
      sum += i;
    if (sum % 2 == 1)
      return false;
    // initializing dp array
    boolean[] prev = new boolean[(sum / 2) + 1];
    boolean[] curr = new boolean[(sum / 2) + 1];
    // main code
    for (int currLength = 1; currLength < N + 1; currLength++) {
      curr[0] = true;
      for (int i = 0; i < (sum / 2) + 1; i++)
        prev[i] = curr[i];

      for (int currSum = 1; currSum < (sum / 2) + 1; currSum++) {
        int currNum = nums[currLength - 1];
        boolean take = currNum <= currSum ? prev[currSum - currNum] : false;
        boolean notTake = prev[currSum];
        curr[currSum] = take || notTake;
      }
    }
    return curr[(sum / 2)];
  }
}

class Solution {
  boolean canPartition(int[] nums) {
    return new Solve().solveSapceOptmized(nums);
  }
}
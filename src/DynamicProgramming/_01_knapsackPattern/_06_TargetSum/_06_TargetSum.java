// https://leetcode.com/problems/target-sum/
// Leetcode TBD
package DynamicProgramming._01_knapsackPattern._06_TargetSum;

class Helper {
  public static int getSum(int[] arr) {
    int sum = 0;
    for (int i : arr)
      sum += i;
    return sum;
  }
}

class Solve {
  // recursive
  public int solveRecursive(int[] nums, int target) {
    int sum = Helper.getSum(nums);
    if ((sum - target) % 2 == 1 || target > sum)
      return 0;
    int length = nums.length;
    int set2 = (sum - target) / 2;
    return solveRecursive(length, set2, nums);
  }

  public int solveRecursive(int length, int target, int[] nums) {
    // base case
    if (length == 0)
      return target == 0 ? 1 : 0;
    // main code
    int currNum = nums[length - 1];
    int take = currNum <= target ? solveRecursive(length - 1, target - currNum, nums) : 0;
    int notTake = solveRecursive(length - 1, target, nums);
    return take + notTake;
  }
}

class Solution {
  public int findTargetSumWays(int[] nums, int target) {
    return new Solve().solveRecursive(nums, target);
  }
}
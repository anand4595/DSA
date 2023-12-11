// https://leetcode.com/problems/binary-search/
package BinarySearch._01_standardBinarySearch;

class Solve {
  // TC - O(log(n))
  // SC - O(log(n))
  public int solveRecursion(int[] nums, int target) {
    int s = 0;
    int e = nums.length - 1;
    return solveRecursion(s, e, target, nums);
  }

  public int solveRecursion(int s, int e, int target, int[] nums) {
    // base case
    if (s > e)
      return -1;
    // main case
    int mid = (s + e) / 2;
    int num = nums[mid];
    if (num == target)
      return mid;
    else if (num < target)
      return solveRecursion(mid + 1, e, target, nums);
    else
      return solveRecursion(s, mid - 1, target, nums);
  }

  // TC - O(log(n))
  // SC - O(1)
  public int solveIterative(int[] nums, int target) {
    int s = 0;
    int e = nums.length - 1;
    while (s <= e) {
      int mid = (s + e) / 2;
      int num = nums[mid];
      if (num == target)
        return mid;
      else if (num < target)
        s = mid + 1;
      else
        e = mid - 1;
    }
    return -1;
  }
}

class Solution {
  public int search(int[] nums, int target) {
    return new Solve().solveIterative(nums, target);
  }
}
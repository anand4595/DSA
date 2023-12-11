// https://leetcode.com/problems/search-insert-position/

package BinarySearch._02_Floor_Ciel_pattern._03_SearchInsertPosition;

class Solve {
  // Brute force using linear search

  // TC - O(n)
  // SC - O(1)
  public int linearSearch(int[] nums, int target) {
    // base case
    if (nums[nums.length - 1] < target)
      return nums.length;
    int i = 0;
    for (i = 0; i < nums.length; i++)
      if (nums[i] >= target)
        break;
    return i;
  }

  // optimized using binary search approch iterative and recursive

  // TC - O(log(n))
  // SC - O(1)
  public int BinarySearchIterative(int[] nums, int target) {
    // base case
    if (nums[nums.length - 1] < target)
      return nums.length;

    // main code
    int start = 0;
    int end = nums.length - 1;
    int ans = end;

    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        start = mid + 1;
      else {
        ans = mid;
        end = mid - 1;
      }
    }

    return ans;
  }

  public int BinarySearchRecursive(int[] nums, int target) {
    if (nums[nums.length - 1] < target)
      return nums.length;

    int s = 0;
    int e = nums.length - 1;
    int ans = e;
    return BinarySearchRecursive(s, e, ans, target, nums);
  }

  public int BinarySearchRecursive(int s, int e, int ans, int target, int[] nums) {
    // base case
    if (s > e)
      return ans;

    int mid = (s + e) / 2;

    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target) {
      s = mid + 1;
      return BinarySearchRecursive(s, e, ans, target, nums);
    } else {
      ans = mid;
      e = mid - 1;
      return BinarySearchRecursive(s, e, ans, target, nums);
    }
  }
}

class Solution {
  public int searchInsert(int[] nums, int target) {
    return new Solve().BinarySearchRecursive(nums, target);
  }
}
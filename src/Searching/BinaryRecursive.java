// https://leetcode.com/problems/binary-search/description/

package Searching;

class Solution {

  /**
   * Binary search algorithm to find index of given target from the array.
   * <p>
   * TC - O(log(n))
   * </p>
   * <p>
   * SC - O(log(n))
   * </p>
   * 
   * @param low    low end of search space
   * @param high   high end of search space
   * @param nums   array to be search
   * @param target target element
   * @return index of the element if found else -1.
   */
  public int binarySearch(int low, int high, int[] nums, int target) {
    if (low > high) {
      return -1;
    }

    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      return binarySearch(mid + 1, high, nums, target);
    } else {
      return binarySearch(low, mid - 1, nums, target);
    }
  }

  public int binarySearch(int[] nums, int target) {
    return binarySearch(0, nums.length - 1, nums, target);
  }

  public int search(int[] nums, int target) {
    return binarySearch(nums, target);
  }
}

public class BinaryRecursive {

}

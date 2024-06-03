// https://leetcode.com/problems/sort-colors/description/

class Solution {

  int ZERO = 0;
  int ONE = 1;

  public void sortColors(int[] nums) {
    int low = 0;
    int mid = 0;
    int high = nums.length - 1;

    while (mid <= high) {
      int num = nums[mid];
      if (num == ZERO) {
        swap(nums, low, mid);
        low++;
        mid++;
      } else if (num == ONE) {
        mid++;
      } else { // equal to three
        swap(nums, mid, high);
        high--;
      }
    }
  }

  private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}

public class Sort_0_1_2 {

}
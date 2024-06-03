// https://leetcode.com/problems/maximum-subarray/description/

package Arrays;

class Solution {
  public int maxSubArray(int[] nums) {
    int sum = 0, max = Integer.MIN_VALUE;

    for (int it : nums) {
      sum += it;
      max = Integer.max(max, sum);
      sum = sum > 0 ? sum : 0;
    }

    return max;
  }
}

public class Maximum_Subarray {

}

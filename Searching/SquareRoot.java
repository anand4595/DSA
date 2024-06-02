// https://www.geeksforgeeks.org/problems/square-root/1

package Searching;

class Solution {
  long floorSqrt(long x) {
    long low = 0;
    long high = x;
    while (low <= high) {
      long mid = (low + high) / 2;
      if (mid * mid == x) {
        return mid;
      } else if (mid * mid < x) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return high;
  }
}

public class SquareRoot {

}

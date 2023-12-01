// https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
package BinarySearch._02_Floor_Ciel_pattern._01_LowerBound;

class Solve {
  // TC - O(log(n))
  // SC - O(log(n))
  public int solveRecursion(int[] arr, int n, int x) {
    if (arr[n - 1] < x)
      return n;
    int s = 0;
    int e = n - 1;
    return solveRecursion(s, e, e, x, arr);
  }

  public int solveRecursion(int s, int e, int ans, int x, int[] arr) {
    // base case
    if (s > e)
      return ans;
    int mid = s + (e - s) / 2;
    int num = arr[mid];
    if (num == x)
      return mid;
    else if (num < x) {
      s = mid + 1;
      return solveRecursion(s, e, ans, x, arr);
    } else {
      ans = mid;
      e = mid - 1;
      return solveRecursion(s, e, ans, x, arr);
    }
  }

  // TC - O(log(n))
  // SC - O(1)
  public int solveIterative(int[] arr, int n, int x) {
    if (arr[n - 1] < x)
      return n;
    int s = 0;
    int e = n - 1;
    int ans = e;
    while (s <= e) {
      int mid = s + (e - s) / 2;
      // number found therefore it is the lower bound itself
      if (arr[mid] == x)
        return mid;
      else if (arr[mid] < x) {
        // start is simply inc. but has no effect on lower bound
        s = mid + 1;
      } else {
        // as x < mid < last ans
        ans = mid;
        e = mid - 1;
      }
    }
    return ans;
  }

}

// public
class Solution {
  public static int lowerBound(int[] arr, int n, int x) {
    return new Solve().solveRecursion(arr, n, x);
  }
}
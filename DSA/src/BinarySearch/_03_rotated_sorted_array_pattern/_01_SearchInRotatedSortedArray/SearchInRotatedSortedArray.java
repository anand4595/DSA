//https://leetcode.com/problems/search-in-rotated-sorted-array/description/

package BinarySearch._03_rotated_sorted_array_pattern._01_SearchInRotatedSortedArray;


class Solve {
    public int linearSearch(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++)
            if (nums[i] == target) return i;
        return -1;
    }

    public int standardBinarySearch(int start, int end, int[] nums, int target) {

        while (start <= end) {

            int mid = (start + end) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }

    public int getPivotIndexUsingBinarySearch(int[] nums, int target) {
        if (nums.length <= 1)
            return 0;

        int start = 0;
        int end = nums.length - 1;
//        int loop = 0;
        while (start <= end) {
//            loop++;
            int mid = (start + end) / 2;

//            System.out.println("Loop: " + loop);
//            System.out.println("Start: " + start);
//            System.out.println("Mid: " + mid);
//            System.out.println("End: " + end);

            if (nums[mid] > nums[mid + 1]) {
//                System.out.println("Returning mid: " + mid);
                return mid;
            } else if (nums[mid] > nums[nums.length - 1]) {
//                System.out.println("Setting start: " + mid + 1);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

    public int usingBinarySearch(int[] nums, int target) {
        int pivot = getPivotIndexUsingBinarySearch(nums, target);

//        System.out.println("final pivot index: " + pivot + " element: " + nums[pivot]);

        if (pivot == -1)
            return standardBinarySearch(0, nums.length - 1, nums, target);

        if (nums[0] <= target && target <= nums[pivot])
            return standardBinarySearch(0, pivot, nums, target);
        else return standardBinarySearch(pivot + 1, nums.length - 1, nums, target);
    }
}

class Solution {
    public int search(int[] nums, int target) {
        return new Solve().usingBinarySearch(nums, target);
    }
}

//public class SearchInRotatedSortedArray {
//    public static void main(String[] args) {
//        Solution s = new Solution();
//        int[] arr = {2, 3, 4, 5, 6, 7, 1};
//        int target = 1;
//        int ans = s.search(arr, target);
//        System.out.println(ans);
//    }
//}
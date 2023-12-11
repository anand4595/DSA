// https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
package BinarySearch._02_Floor_Ciel_pattern._06_count_occurance;


class Solution {
    public static int count(int arr[], int n, int x) {
        //Your code goes here
        return new Solve().usingBinarySearch(arr, n, x);
    }
}

class Solve {
    public int usingLinearSearch(int[] arr, int n, int x) {
        int fo = -1;
        int lo = -1;

        int i = 0;
        while (i < n && arr[i] <= x) {
            if (arr[i] == x) {
                fo = fo == -1 ? i : fo;
                lo = i;
            }
            i++;
        }
        if (lo == -1) return 0;
        return 1 + lo - fo;
    }

    public int usingBinarySearchFirstOcc(int[] arr, int n, int x) {

        int start = 0;
        int end = arr.length - 1;
        int ans = -1;

        while (start <= end) {

            int mid = (start + end) / 2;

            if (arr[mid] == x) {
                ans = mid;
                end = mid - 1;
            } else if (arr[mid] < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }

        return ans;
    }

    public int usingBinarySearchLastOcc(int[] arr, int n, int x) {

        int start = 0;
        int end = arr.length - 1;
        int ans = -1;

        while (start <= end) {

            int mid = (start + end) / 2;

            if (arr[mid] == x) {
                ans = mid;
                start = mid + 1;
            } else if (arr[mid] < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }

        return ans;
    }

    public int usingBinarySearch(int[] arr, int n, int x) {
        int fo = usingBinarySearchFirstOcc(arr, n, x);
        int eo = usingBinarySearchLastOcc(arr, n, x);
        // System.out.println(fo);
        // System.out.println(eo);
        if (fo == -1)
            return 0;
        return 1 + eo - fo;
    }
}


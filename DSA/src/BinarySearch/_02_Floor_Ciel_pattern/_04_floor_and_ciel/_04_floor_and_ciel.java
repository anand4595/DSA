//https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
package BinarySearch._02_Floor_Ciel_pattern._04_floor_and_ciel;

class SolveLowerBound {
    public int usingBinarySearchIterative(int[] a, int n, int x) {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (a[mid] == x) {
                return a[mid];
            } else if (a[mid] < x) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans == -1 ? -1 : a[ans];

    }
}

class SolveUpperBound {
    public int usingBinarySearchIterative(int[] a, int n, int x) {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (a[mid] == x) {
                return a[mid];
            } else if (a[mid] < x) {
                s = mid + 1;
            } else {
                ans = mid;
                e = mid - 1;
            }
        }
        return ans == -1 ? -1 : a[ans];

    }

}

class Solve {
    public int[] usingLinearSearch(int[] a, int n, int x) {
        int lb = -1;
        int ub = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < x) lb = i;
            else if (x < a[i] && ub == -1) {
                ub = i;
            }
        }
        return new int[]{lb, ub};
    }

    public int[] usingBinarySearch(int[] a, int n, int x) {
        int lb = new SolveLowerBound().usingBinarySearchIterative(a, n, x);
        int ub = new SolveUpperBound().usingBinarySearchIterative(a, n, x);
        return new int[]{lb, ub};
    }
}

class Solution {
    public static int[] getFloorAndCeil(int[] a, int n, int x) {
        // Wriute your code here
//		int[] arr = {1, 2};
        return new Solve().usingBinarySearch(a, n, x);
    }
}
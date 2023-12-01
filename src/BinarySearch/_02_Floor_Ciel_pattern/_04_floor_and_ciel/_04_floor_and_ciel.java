//https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
package BinarySearch._02_Floor_Ciel_pattern._04_floor_and_ciel;

class SolveLowerBound {
}

class SolveUpperBound {
}

class Solve {
	public int[] usingLinearSearch(int[] a, int n, int x) {
		int lb = -1;
		int ub = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] < x)
				lb = i;
			else if (x < a[i] && ub == -1) {
				ub = i;
			}
		}
		return new int[]{lb, ub};
	}
}

class Solution {
	public static int[] getFloorAndCeil(int[] a, int n, int x) {
		// Wriute your code here
//		int[] arr = {1, 2};
		return new Solve().usingLinearSearch(a, n, x);
	}
}
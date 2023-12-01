// https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383

package BinarySearch._02_Floor_Ciel_pattern._02_UpperBound;

class Solve {
	//  TC - O(log(n))
	//  SC - O(1)
	public int linearSearch(int[] arr, int x, int n) {
		for (int i = 0; i < n; i++)
			if (x < arr[i]) return i;
		return n;
	}

	//	TC - O(log(n))
	//	SC - O(1)
	public int binarySearchIterative(int[] arr, int x, int n) {
		int low = 0, high = n;

		while (low < high) {
			int mid = low + (high - low) / 2;

			// If x is greater than or equal to arr[mid],
			// we search in [mid+1,high].
			if (arr[mid] <= x) {
				low = mid + 1;
			}
			// Else we search in [low,mid].
			else {
				high = mid;
			}
		}
		// If 'x' is greater than or equal to all the elements of 'arr'.
		if (arr[n - 1] <= x) {
			return n;
		}
		return low;
	}
}

class Solution {
	public static int upperBound(int[] arr, int x, int n) {
		return new Solve().binarySearchIterative(arr, x, n);
	}
}
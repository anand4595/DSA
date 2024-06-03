// https://leetcode.com/problems/rotate-image/description/

package Arrays;

class Solution {
  private void swap(int[][] matrix, int i, int j) {
    int temp = matrix[i][j];
    matrix[i][j] = matrix[j][i];
    matrix[j][i] = temp;
  }

  private void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  private void transpose(int[][] matrix) {
    int row = matrix.length;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j <= i; j++) {
        swap(matrix, i, j);
      }
    }
  }

  private void swapColumns(int[][] matrix) {
    for (int i = 0; i < matrix.length; i++) {
      int low = 0;
      int high = matrix[i].length - 1;
      while (low < high) {
        swap(matrix[i], low, high);
        low++;
        high--;
      }
    }
  }

  public void rotate(int[][] matrix) {
    transpose(matrix);
    swapColumns(matrix);
  }
}

public class Matrix_rotation {

}

// https://leetcode.com/problems/spiral-matrix/description/

package Arrays;

import java.util.ArrayList;
import java.util.List;

class Solution {

  enum Direction {
    RIGHT, DOWN, LEFT, UP
  }

  public List<Integer> spiralOrder(int[][] matrix) {
    List<Integer> traversal = new ArrayList<>();

    int lapCount = 0;
    var direction = Direction.RIGHT;
    final int elementCount = matrix.length * matrix[0].length;

    while (traversal.size() < elementCount) {
      switch (direction) {
        case RIGHT -> processRightDir(traversal, matrix, lapCount);
        case DOWN -> processDownDir(traversal, matrix, lapCount);
        case LEFT -> processLeftDir(traversal, matrix, lapCount);
        case UP -> processUpDir(traversal, matrix, lapCount);
        // default -> throw new Exception("spiralOrder - Reached unknown state" +
        // direction);
      }

      if (direction == Direction.UP) {
        lapCount++;
      }

      direction = Direction.values()[(direction.ordinal() + 1) / Direction.values().length];
    }

    return new ArrayList<>();
  }

  void processRightDir(List<Integer> traversal, int[][] matrix, int lapCount) {

  }

  void processLeftDir(List<Integer> traversal, int[][] matrix, int lapCount) {

  }

  void processUpDir(List<Integer> traversal, int[][] matrix, int lapCount) {

  }

  void processDownDir(List<Integer> traversal, int[][] matrix, int lapCount) {

  }
}

public class Matrix_traversal {

}

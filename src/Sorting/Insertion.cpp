// https://www.geeksforgeeks.org/problems/insertion-sort/1
/**
 * TC - O(N^2)
 * SC - O(1)
 */

#include <iostream>
using namespace std;

class Solution
{
public:
  // Function to sort the array using insertion sort algorithm.
  void insertionSort(int arr[], int n)
  {
    for (int i = 1; i < n; i++)
    {
      int key = arr[i];
      int j = i - 1;

      // Moving elements from [0 .. i - 1] to correct position
      while (j >= 0 && arr[j] > key)
      {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
      arr[j + 1] = key;
    }
  }
};
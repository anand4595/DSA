// https://www.geeksforgeeks.org/problems/selection-sort/1
/**
 * TC - O(n^2)
 * SC - O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void swap(int arr[], int x, int y)
  {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }

  void selectionSort(int arr[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      int minIdx = i;
      for (int j = i + 1; j < n; j++)
      {
        if (arr[j] < arr[minIdx])
          minIdx = j;
      }
      swap(arr, i, minIdx);
    }
  }
};

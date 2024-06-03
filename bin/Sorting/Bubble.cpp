// https://www.geeksforgeeks.org/problems/bubble-sort/1
/**
 * TC - O(n^2)
 * SC - O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class BubbleSort
{
private:
  void swap(int arr[], int idx1, int idx2)
  {
    arr[idx1] = arr[idx1] ^ arr[idx2];
    arr[idx2] = arr[idx1] ^ arr[idx2];
    arr[idx1] = arr[idx1] ^ arr[idx2];
  }

public:
  // every pass the largest element is moved to end
  void sort(int arr[], int n)
  {
    for (int i = 0; i < n - 1; i++)
    {
      bool swaped = false;
      for (int j = 0; j < n - 1; j++)
      {
        if (arr[j] > arr[j + 1])
        {
          swap(arr, j, j + 1);
          swaped = true;
        }
      }
      if (!swaped)
      {
        return;
      }
    }
  }
};

class Solution
{
public:
  // Function to sort the array using bubble sort algorithm.
  void bubbleSort(int arr[], int n)
  {
    BubbleSort sort;
    sort.sort(arr, n);
  }
};
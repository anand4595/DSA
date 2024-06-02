#include <bits/stdc++.h>
using namespace std;

template <class T>
class Heap
{
  vector<T> arr;
  Heap();
  void insert(T key);
  T peek();
  T pop();
};
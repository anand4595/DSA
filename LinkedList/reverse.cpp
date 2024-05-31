// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

class ReverseList
{
public:
  /**
   * TC - O(n)
   * SC - O(n)
   */
  static Node *reverse_using_stack(Node *root)
  {
    // If root == NULL then return root itself
    if (root == NULL)
    {
      return NULL;
    }
    stack<int> stk;

    Node *ptr = root;
    while (ptr != NULL)
    {
      stk.push(ptr->data);
      ptr = ptr->next;
    }

    ptr = root;
    while (!stk.empty())
    {
      ptr->data = stk.top();
      stk.pop();
      ptr = ptr->next;
    }
  }

  /**
   * TC - O(n)
   * SC - O(1)
   */
  static Node *reverse_using_three_pointer(Node *head)
  {
    Node *prev = NULL, *curr = NULL, *next = head;
    while (next != NULL)
    {
      curr = next;
      next = curr->next;
      curr->next = prev;
      prev = curr;
    }
    return curr;
  }
};

class Solution
{
public:
  struct Node *reverseList(struct Node *head)
  {
    return ReverseList::reverse_using_three_pointer(head);
  }
};
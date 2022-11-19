// https://practice.geeksforgeeks.org/problems/inorder-traversal/1
#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
using vi = vector<int>;

void inorder(Node *root,vi &tra){
    if (!root) return ;
    inorder(root->left,tra);
    tra.push_back(root->data);
    inorder(root->right,tra);
}

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vi tra;
        inorder(root,tra);
        return tra;
    }
};

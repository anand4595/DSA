// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
#include <bits/stdc++.h>

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

class Code {
public:
int isBalanced(Node *root){
    if (root==NULL) return 0;
    int leftSubTree = isBalanced(root->left);
    if (leftSubTree == -1) return -1;
    int rightSubTree = isBalanced(root->right);
    if (rightSubTree == -1) return -1;
    if (abs(leftSubTree-rightSubTree) > 1) return -1;
    return 1 + max(leftSubTree,rightSubTree);
}
};


class Solution{
public:
bool isBalanced(Node *root){
    Code obj;
    return obj.isBalanced(root) != -1;
}
};
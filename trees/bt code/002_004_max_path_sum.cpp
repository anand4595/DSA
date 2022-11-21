#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left,*right;
};

class Code {
public:
int maxi;
Code (){this ->maxi = INT32_MIN;}
int maxPath (Node * root){
    if (!root) return 0;
    int left = maxPath(root->left);
    int right = maxPath(root->right);
    maxi = max(maxi,left+right+root->data);
    return max(0,root->data+max(left,right));
}
};

class Solution {
public:
//Function to return maximum path sum from any node in a tree.
int findMaxSum(Node* root){
    Code obj;
    obj.maxPath(root);
    return obj.maxi;
}
};
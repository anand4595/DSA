// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
#include <iostream>
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



class Solution{
public:
int height(struct Node* node){ 
    if (!node) return 0;
    return 1 + max(height(node->left),height(node->right));
}
};
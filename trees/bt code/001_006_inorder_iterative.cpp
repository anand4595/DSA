// https://practice.geeksforgeeks.org/problems/inorder-traversal/1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using vi = vector<int>;


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


class Solution {
public:
vector<int> inOrder(Node* root){
    stack<Node*> stk;
    vi traversal;
    while (!stk.empty() || root){
        while (root){
            stk.push(root);
            root = root->left;
        }
        if (!root){
            traversal.push_back(stk.top()->data);
            root = stk.top()->right;
            stk.pop();
        }
    }
    return traversal;
}
};
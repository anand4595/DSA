// https://practice.geeksforgeeks.org/problems/preorder-traversal/1
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
#include <stack>

vector <int> preorder(Node* root){
    vector<int> traversal;
    stack<Node*> stk;
    stk.push(root);
    while (!stk.empty()){
        Node *node = stk.top();
        stk.pop();
        traversal.push_back(node->data);
        if (node->right)
            stk.push(node->right);
        if (node->left)
            stk.push(node->left);
    }
    return traversal;
}
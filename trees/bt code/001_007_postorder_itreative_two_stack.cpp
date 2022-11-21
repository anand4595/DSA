// https://practice.geeksforgeeks.org/problems/postorder-traversal/1
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

vector <int> postOrder(Node* root){
    vi traversal;
    stack<Node*> stk1;
    stack<int> stk2;
    stk1.push(root);
    while (!stk1.empty()){
        Node* node = stk1.top();
        stk1.pop();
        stk2.push(node->data);
        if (node->left) stk1.push(node->left);
        if (node->right) stk1.push(node->right);
    }
    while (!stk2.empty()){
        traversal.push_back(stk2.top());
        stk2.pop();
    }
    return traversal;
}
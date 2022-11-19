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
using vi = vector<int>;

void preorder (Node * root,vi &tra){
    if (!root) return;
    tra.push_back(root->data);
    preorder(root->left,tra);
    preorder(root->right,tra);
}

vector <int> preorder(Node* root){
    vi tra;
    preorder(root,tra);
    return tra;
}
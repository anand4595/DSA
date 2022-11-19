// https://practice.geeksforgeeks.org/problems/postorder-traversal/1
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

void postOrder(Node *root,vi &tra){
    if (!root) return ;
    postOrder(root->left,tra);
    postOrder(root->right,tra);
    tra.push_back(root->data);
}

vector <int> postOrder(Node* root)
{
  // Your code here
  vi ans;
  postOrder(root,ans);
  return ans;
}


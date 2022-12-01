#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
public:
vector <int> zigZagTraversal(Node* root){
    vector<int> traversal;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool reverse = 1;
    while (q.size() > 1){
        Node * node = q.front();
        q.pop();
        if (!reverse && node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (reverse && node->left) q.push(node->right);
        if (node) traversal.push_back(node->data);
        else {
            reverse = !reverse;
            q.push(NULL);    
        };
    }
    return traversal;
}
};
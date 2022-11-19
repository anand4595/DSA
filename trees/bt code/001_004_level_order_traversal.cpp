// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
#include <vector>
#include <iostream>
#include <queue>
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
vector<int> levelOrder(Node* node){
    vector<int> traversal;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()){
        traversal.push_back(q.front()->data);
        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
    return traversal;
}
};
// https://practice.geeksforgeeks.org/problems/postorder-traversal/1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using vi = vector<int>;


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector <int> postOrder(Node* root){
    vector <int> postOrder;
    if (root == NULL) return postOrder;
    Node * cur = root;
    stack < Node * > st;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) {
            st.push(cur);
            cur = cur -> left;
        } 
        else {
            Node * temp = st.top() -> right;
            if (temp == NULL) {
            temp = st.top();
            st.pop();
            postOrder.push_back(temp -> data);
            while (!st.empty() && temp == st.top() -> right) {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp -> data);
            }
        } 
        else cur = temp;
        }
    }
    return postOrder;
}
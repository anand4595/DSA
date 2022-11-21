// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

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

class Code {
public:
int maxi;
int diameter(Node * root){
	if (!root) return 0;
	int left = diameter(root->left);
	int right = diameter(root->right);
	maxi = max(maxi,left+right+1);
	return 1 + max(left,right);
}
};

class Solution {
public:
int diameter(Node* root) {
	Code obj;
	obj.maxi = 0;
	obj.diameter(root);
	return obj.maxi;
}
};      
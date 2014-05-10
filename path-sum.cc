#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Definition for binary tree
 **/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
    	if(root==NULL) return false;
    	queue<pair<TreeNode*, int> > Q;
    	Q.push(make_pair(root,root->val));
    	while(Q.size()){
    		pair<TreeNode*, int> top = Q.front();
    		TreeNode* node = top.first;
    		int cur = top.second;
    		Q.pop();
    		if(node->left!=NULL)
    			Q.push(make_pair(node->left, node->left->val + cur));
    		if(node->right!=NULL)
    			Q.push(make_pair(node->right, node->right->val + cur));
    		if(node->left==NULL && node->right==NULL && cur == sum)
    			return true;
    	}
        return false;
    }
};

int main(){}
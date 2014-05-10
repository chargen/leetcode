#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> ss;
        vector<int> ans;
        if(root){
	        ss.push(root);
	        while(ss.size()){
	        	TreeNode* top = ss.top();
	        	ss.pop();
	        	ans.push_back(top->val);
	        	if(top->right != NULL) ss.push(top->right);
	        	if(top->left != NULL) ss.push(top->left);
	        }
    	}
        return ans;
    }
};

int main(){}
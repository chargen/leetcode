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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> ss;
        stack<int>mark;
        vector<int> ans;
        if(root){
	        ss.push(root);
	        mark.push(0);
	        while(ss.size()){
	        	TreeNode* top = ss.top();
	        	if(mark.top() == 0){
	        		mark.pop();
	        		mark.push(1);
	        		if(top->right != NULL) ss.push(top->right), mark.push(0);
	        		if(top->left != NULL) ss.push(top->left), mark.push(0);
	        	}else{
	        		ans.push_back(top->val);
	        		mark.pop();
	        		ss.pop();
	        	}
	        }
    	}
        return ans;
    }
};

int main(){}
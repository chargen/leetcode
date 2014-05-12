#include <iostream>
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
	TreeNode *p[2];
	TreeNode *last;
	void findNode(TreeNode *root){
		if(root->left != NULL)
			findNode(root->left);
		if(last != NULL && root->val < last->val){
			if(p[0] == NULL) p[0] = last;
			p[1] = root;
		}
		last = root;
		if(root->right != NULL)	findNode(root->right);
		return;
	}
    void recoverTree(TreeNode *root) {
    	p[0] = NULL;
    	p[1] = NULL;
    	last = NULL;
    	findNode(root);
    	swap(p[0]->val, p[1]->val);
    }
};



int main(){
	Solution sol;
	TreeNode *p = new TreeNode(2);
	p->right = new TreeNode(1);
	sol.recoverTree(p);
}
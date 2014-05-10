/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool checkSymmetric(TreeNode* lRoot, TreeNode* rRoot){
    	if(lRoot == NULL && rRoot == NULL) return true;
    	if(lRoot == NULL || rRoot == NULL) return false;
    	if(lRoot->val != rRoot->val) return false;
    	return checkSymmetric(lRoot->left, rRoot->right)
    		&& checkSymmetric(lRoot->right, rRoot->left); 
	}

    bool isSymmetric(TreeNode *root) {
    	if(root == NULL) return true;
    	return checkSymmetric(root->left, root->right);	
    }
};
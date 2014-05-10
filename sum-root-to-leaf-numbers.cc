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
	int ans = 0;
	int sumNumbers(TreeNode *root, int k){
		k = k * 10 + root->val;
		if(root->left == NULL && root->right == NULL) ans += k;
		if(root->left != NULL) sumNumbers(root->left, k);
		if(root->right != NULL) sumNumbers(root->right, k);
	}
    int sumNumbers(TreeNode *root) {
    	ans = 0;
        if(root != NULL) sumNumbers(root, 0);
        return ans;
    }
};
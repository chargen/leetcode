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
	bool isValidBST(TreeNode *node, int& minVal, int& maxVal){
		if(node->left == NULL && node->right == NULL){
			minVal = node->val;
			maxVal = node->val;
			return true;
		}
		if(node->left != NULL){
			int minV, maxV;
			if(!isValidBST(node->left, minV, maxV) || maxV >= node->val)
				return false;
			minVal = minV;
		}else
			minVal = node->val;
		if(node->right != NULL){
			int minV, maxV;
			if(!isValidBST(node->right, minV, maxV) || minV <= node->val)
				return false;
			maxVal = maxV;
		}else
			maxVal = node->val;
		return true;
	}
    bool isValidBST(TreeNode *root) {
    	int minVal, maxVal;
    	if(root == NULL) return true;
		return isValidBST(root, minVal, maxVal);
    }
};
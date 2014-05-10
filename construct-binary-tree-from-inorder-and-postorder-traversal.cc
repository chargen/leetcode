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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int iL, int iR, int pL, int pR) {
		if(pL == pR) return NULL;
		TreeNode* root = new TreeNode(postorder[pR-1]);
		for(int i = iL; i < iR; ++i){
			if(inorder[i] == root->val){
				root->left = buildTree(inorder, postorder, iL, i, pL, pL+i-iL);
				root->right = buildTree(inorder, postorder, i+1, iR, pL+i-iL, pR-1);
			}
		}
		return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
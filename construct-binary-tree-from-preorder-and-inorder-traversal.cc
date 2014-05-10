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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pL, int pR, int iL, int iR){
		if(pL == pR) return NULL;
		TreeNode* root = new TreeNode(preorder[pL]);
		for(int i = iL; i < iR; ++i){
			if(inorder[i] == root->val){
				root->left = buildTree(preorder, inorder, pL+1, pL+1+i-iL, iL, i);
				root->right = buildTree(preorder, inorder, pL+1+i-iL, pR, i+1, iR);
			}
		}
		return root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
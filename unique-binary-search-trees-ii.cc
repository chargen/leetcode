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
    vector<TreeNode *> generateTrees(int l, int r){
    	vector<TreeNode *> ans;
    	if(l == r) {
    		ans.push_back(NULL);
    		return ans;
		}
    	for(int val = l; val < r; ++val){
    		vector<TreeNode*> ltree = generateTrees(l, val);
    		vector<TreeNode*> rtree = generateTrees(val+1, r);
    		for(int i = 0; i < ltree.size(); ++i){
    			for(int j = 0; j < rtree.size(); ++j){
		    		TreeNode *root = new TreeNode(val+1);
		    		root->left = ltree[i];
		    		root->right = rtree[j];
		    		ans.push_back(root);
    			}
    		}
    	}
    	return ans;
    }
    vector<TreeNode *> generateTrees(int n) {
   		return generateTrees(0, n);
    }
};
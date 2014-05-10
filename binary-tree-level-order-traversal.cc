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
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ans;
    	if(root){
    		vector<TreeNode*> preLevel;
    		vector<TreeNode*> curLevel;
    		preLevel.push_back(root);
    		vector<int> cur;
    		cur.push_back(root->val);
	    	while(preLevel.size() > 0){
	    		ans.push_back(cur);
	    		cur.clear();
	    		curLevel.clear();
	    		for(int i = 0; i < preLevel.size(); ++i){
	    			TreeNode *node = preLevel[i];
	    			if(node->left){
	    				cur.push_back(node->left->val);
	    				curLevel.push_back(node->left);
	    			}
	    			if(node->right){
	    				cur.push_back(node->right->val);
	    				curLevel.push_back(node->right);
	    			}
	    		}
	    		curLevel.swap(preLevel);
	    	}
    	}
    	return ans;
    }
};
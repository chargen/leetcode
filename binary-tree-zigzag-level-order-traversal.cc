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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
    	if(root){
    		vector<TreeNode*> preLevel;
    		vector<TreeNode*> curLevel;
    		preLevel.push_back(root);
    		vector<int> cur;
    		cur.push_back(root->val);
    		int level = 1;
	    	while(preLevel.size() > 0){
	    		ans.push_back(cur);
	    		cur.clear();
	    		curLevel.clear();
	    		for(int i = preLevel.size() - 1; i >= 0 ; --i){
	    			TreeNode *node = preLevel[i];
	    			if(level == 0){
		    			if(node->left){
		    				cur.push_back(node->left->val);
		    				curLevel.push_back(node->left);
		    			}
		    			if(node->right){
		    				cur.push_back(node->right->val);
		    				curLevel.push_back(node->right);
		    			}
	    			}else{
	    				if(node->right){
		    				cur.push_back(node->right->val);
		    				curLevel.push_back(node->right);
		    			}
		    			if(node->left){
		    				cur.push_back(node->left->val);
		    				curLevel.push_back(node->left);
		    			}
	    			}
	    		}
	    		curLevel.swap(preLevel);
	    		level ^= 1;
	    	}
    	}
    	return ans;
    }
};
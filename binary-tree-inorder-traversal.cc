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
    vector<int> inorderTraversal(TreeNode *root) {
    	stack<pair<TreeNode *, int> > ss;
    	vector<int> ans;
    	if(root != NULL){
    		ss.push(make_pair(root, 0));
    		while(ss.size()){
    			TreeNode *node = ss.top().first;
    			int tag = ss.top().second;
    			ss.pop();
    			if(tag)	ans.push_back(node->val);
    			else{
    				if(node->right)
    					ss.push(make_pair(node->right, 0));
    				ss.push(make_pair(node, 1));
    				if(node->left)
    					ss.push(make_pair(node->left, 0));
    			}
    		}
    	}
    	return ans;
    }
};
#include <vector>
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
	void dfs(TreeNode* node, int cur, int target, std::vector<int>& ss, vector<vector<int> >&ans){
		ss.push_back(node->val);
		cur += node->val;
		if(node->left != NULL) dfs(node->left, cur, target, ss, ans);
		if(node->right != NULL) dfs(node->right, cur, target, ss, ans);
		if(node->left == NULL && node->right == NULL && cur == target)
			ans.push_back(ss);
		ss.pop_back();
	}
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<int> ss;
		vector<vector<int> > ans;
		if(root) dfs(root, 0, sum, ss, ans);
    	return ans;
    }
};

int main(){}
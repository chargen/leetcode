#include <iostream>
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
	const static int INF = 0x3f3f3f3f;
	void maxPathSumDFS(TreeNode* node, int& maxRootPathSum, int& maxPathSum){
		if(node->left == NULL||node->right == NULL ){
			maxRootPathSum = node->val;
			maxPathSum = node->val;
		}
		int maxRootPathSumLeft = -INF, maxPathSumLeft = -INF;
		int maxRootPathSumRight = -INF, maxPathSumRight = -INF;
		if(node->left != NULL)
			maxPathSumDFS(node->left, maxRootPathSumLeft, maxPathSumLeft);
		if(node->right != NULL)
			maxPathSumDFS(node->right, maxRootPathSumRight, maxPathSumRight);
		maxRootPathSum = max(maxRootPathSumLeft, maxRootPathSumRight) + node->val;
		maxRootPathSum = max(maxRootPathSum, node->val);

		maxPathSum = max(maxPathSumLeft, maxPathSumRight);
		maxPathSum = max(maxPathSum, maxRootPathSum);
		maxPathSum = max(maxPathSum, maxRootPathSumLeft + maxRootPathSumRight + node->val);
	}


    int maxPathSum(TreeNode *root) {
        int maxRootPathSum, maxPathSum;
        maxPathSumDFS(root, maxRootPathSum, maxPathSum);
        return maxPathSum;
    }
};

int main(){

}
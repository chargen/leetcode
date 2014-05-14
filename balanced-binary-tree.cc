class Solution {
public:
	bool isBalanced(TreeNode *node, int& depth){
		int heightL = 0, heightR = 0;
		if(node->left !=NULL )
			if(!isBalanced(node->left, heightL))
				return false;
		if(node->right !=NULL )
			if(!isBalanced(node->right, heightR))
				return false;
		depth = max(heightL, heightR) + 1;
		return heightL - heightR >=-1 && heightL - heightR <=1;
	}

    bool isBalanced(TreeNode *root) {
    	int depth;
    	return root == NULL || isBalanced(root, depth);
    }
};
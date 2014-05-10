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
	void flatten(TreeNode *node, TreeNode *&tail){
		if(node->left == NULL && node->right == NULL){
			tail = node;
			return;
		}
		TreeNode *ltail = NULL, *rtail = NULL;
		if(node->left != NULL) flatten(node->left, ltail);
		if(node->right != NULL) flatten(node->right, rtail);
		if(node->left == NULL){
			tail = rtail;
		}else if(node->right == NULL){
			node->right = node->left;
			node->left = NULL;
			tail = ltail;
		}else{
			ltail->right = node->right;
			node->right = node->left;
			node->left = NULL;
			tail = rtail;
		}
		return;
	}
    void flatten(TreeNode *root) {
        TreeNode *tail;
        if(root != NULL)flatten(root, tail);
    }
};

int main(){
	return 0;
}
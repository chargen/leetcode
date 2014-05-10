#include <iostream>
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
	TreeNode *sortedArrayToBST(const vector<int> &num, int l, int r){
		TreeNode *root;
		if(l == r) root = NULL;
		else if(l+1==r) root = new TreeNode(num[l]);
		else{
			int mid = l + (r-l-1)/2;
			root = new TreeNode(num[mid]);
			root->left = sortedArrayToBST(num, l, mid);
			root->right = sortedArrayToBST(num, mid+1, r);
		}
		return root;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
    	int n = num.size();
    	return n == 0 ? NULL : sortedArrayToBST(num, 0, n);
    }
};

int main(){
	int array[] = {1, 3};
	Solution sol;
	vector<int> num(array, array+2);
	sol.sortedArrayToBST(num);
}
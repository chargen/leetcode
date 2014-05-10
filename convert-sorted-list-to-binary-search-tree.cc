/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
	TreeNode *buildTree(int l, int r, ListNode* &p){
		TreeNode* root;
		if(l == r) return NULL;
		else{
			int mid = (l+r)/2;
			TreeNode* lt = buildTree(l, mid, p);
			root = new TreeNode(p->val);
			p = p->next;
			TreeNode* rt = buildTree(mid+1, r, p);
			root->left = lt;
			root->right = rt;
		}
		return root;
	}
    TreeNode *sortedListToBST(ListNode *head) {
    	ListNode* p = head;
    	int n = 0;
    	while( p!= NULL ){
    		++n;
    		p = p->next;
    	}
    	return buildTree(0, n, head);
    }
};
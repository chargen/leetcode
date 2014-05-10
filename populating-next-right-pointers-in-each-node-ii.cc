/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	TreeLinkNode pre(0), cur(0);
		pre.next = root;
		while(pre.next != NULL){
			cur.next = NULL;
			TreeLinkNode *p = pre.next;
			TreeLinkNode *q = &cur;
			while(p != NULL){
				if(p->left != NULL){
					q->next = p->left;
					q = q->next;
				}
				if(p->right != NULL){
					q->next = p->right;
					q = q->next;
				}
				p = p->next;
			}
			swap(pre, cur);
		}
    }
};
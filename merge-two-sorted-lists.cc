/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode *head;
    	head->next = NULL;
    	ListNode *p = l1, *q = l2, *r = head;
    	while(p != NULL && q != NULL){
    		if(p->val > q->val){
    			r->next = q;
    			q = q->next;
    			r = r->next;
    		}else{
    			r->next = p;
    			p = p->next;
    			r = r->next;
    		}
    	}
    	if(p != NULL) r->next = p;
    	if(q != NULL) r->next = q;
    	return head->next;
    }
};
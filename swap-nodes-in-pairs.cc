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
    ListNode *swapPairs(ListNode *head) {
    	ListNode root(0);
    	root.next = head;
    	ListNode *front = &root;
    	while(front->next != NULL && front->next->next != NULL){
    		ListNode *tail = front->next->next->next;
    		ListNode *p = front->next;
    		ListNode *q = p->next;
    		front->next = q;
    		q->next = p;
    		p->next = tail;
    		front = p;
    	}
    	return root.next;
    }
};
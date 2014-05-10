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
    ListNode *rotateRight(ListNode *head, int k) {
    	if(head == NULL) return NULL;
    	ListNode *p, *q;
    	p = head;
    	while(p->next != NULL) p = p->next;
    	p->next = head;
    	p = q = head;
    	for(int i = 0; i < k; ++i) p = p->next;
    	while(p->next != head)
    		p = p->next, q = q->next;
    	p = q->next;
    	q->next = NULL;
    	return p;
    }
};
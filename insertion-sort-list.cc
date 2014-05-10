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
    ListNode *insertionSortList(ListNode *head) {
    	ListNode sorted(0);
    	for(ListNode *p = head; p != NULL;){
    		ListNode *q = &sorted, *e = p;
    		p = p->next;
    		while(q->next != NULL && e->val > q->next->val)
    			q = q->next;
    		e->next = q->next;
    		q->next = e;
    	}
    	return sorted.next;
    }
};
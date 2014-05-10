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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode l(0);
    	l.next = head;
    	ListNode *p1, *p2;
    	p1 = &l;
    	p2 = &l;
    	for(int i = 0; i < n; ++i)
    		p2 = p2->next;
    	while(p2->next != NULL){
    		p2 = p2->next;
    		p1 = p1->next;
    	}
    	p1->next = p1->next->next;
    	return l.next;
    }
};
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
    ListNode *detectCycle(ListNode *head) {
    	ListNode *p, *q;
    	p = q = head;
    	do{
    		if(q == NULL || q->next == NULL) return NULL;
    		p = p-> next;
    		q = q-> next;
    		q = q-> next;
    	}while(p != q);
    	p = head;
    	while( p != q ){
    		p = p->next;
    		q = q->next;
    	}
    	return p;
    }
};
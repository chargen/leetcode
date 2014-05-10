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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	ListNode *p, *q, *t;
    	ListNode *front, *back;
    	front = head;
    	for(int i = 1; i < m-1; ++i)
    		front = front->next;
    	p = NULL;
    	q = front->next;
    	for(int i = 0; i < n-m+1; ++i){
    		t = q->next;
    		q->next = p;
    		p = q;
    		q = t;
    	}
    	return p;
    }
};
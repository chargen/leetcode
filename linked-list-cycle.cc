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
    bool hasCycle(ListNode *head) {
    	ListNode *p1, *p2;
    	p1 = p2 = head;
    	while(p2 != NULL){
    		if(p2->next != NULL) p2 = p2->next;
    		else return false;
    		if(p2 == p1) return true;
    		if(p2->next != NULL) p2 = p2->next;
    		else return false;
    		if(p2 == p1) return true;
    		p1 = p1->next;
    	}
    	return false;
    }
};
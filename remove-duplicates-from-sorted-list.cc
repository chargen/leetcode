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
    ListNode *deleteDuplicates(ListNode *head) {
    	ListNode *p = head;
    	while(p && p->next != NULL){
    		if(p->val != p->next->val){
    			p = p->next;
    		}else{
    			p->next = p->next->next;
    		}
    	}
    	return head;
    }
};
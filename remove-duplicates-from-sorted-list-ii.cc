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
    	ListNode newHead(0);
        ListNode *result = &newHead;
        ListNode *p = head;
    	while(p!=NULL){
            ListNode* q = p;
            while(q !=NULL && p->val == q->val) q = q->next;
            if(p->next == q){
                result->next = p;
                result = p;
                result->next = NULL;
            }
            p = q;
    	}
    	return newHead.next;
    }
};
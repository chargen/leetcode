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
        if(m == n) return head;
        ListNode root(0);
        root.next = head;
        ListNode* p = &root;
        for(int i = 1; i < m; ++i) p = p->next;
        ListNode* tail = p, *newtail = p->next;
        p = p->next, tail->next = NULL;
        for(int i = 0; i <= n - m; ++i){
            ListNode *t = p->next;
            p->next = tail->next;
            tail->next = p;
            p = t;
        }
        newtail->next = p;
    	return root.next;
    }
};
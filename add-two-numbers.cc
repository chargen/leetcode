#include <iostream>
/**
 * Definition for singly-linked list.
 **/
struct ListNode {
	int val;
 	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	ListNode head = ListNode(0);
    	ListNode *p = &head;
    	int carry = 0;
    	while(l1!=NULL || l2!=NULL || carry){
    		int d = carry;
    		if(l1!=NULL) d += l1->val;
    		if(l2!=NULL) d += l2->val;
    		p->next = new ListNode(d%10);
    		carry = d/10;
    		p = p->next;
    		if(l1!=NULL)l1 = l1->next;
    		if(l2!=NULL)l2 = l2->next;
    	}
    	return head.next;
    }
};

int main(){

}

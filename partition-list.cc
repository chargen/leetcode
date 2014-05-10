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
    ListNode *partition(ListNode *head, int x) {
    	ListNode lessHead(0), largerHead(0);
    	ListNode *lt = &lessHead, *gt = &largerHead;
    	for(ListNode *p = head;
    		p!=NULL;
    		p=p->next){
    		if(p->val < x){
    			lt->next = p;
    			lt = p;
    		}else{
    			gt->next = p;
    			gt = p;
    		}
    	}
    	gt->next=NULL;
    	lt->next=largerHead.next;
    	return lessHead.next;
    }
};
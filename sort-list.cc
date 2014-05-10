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
    ListNode *sortList(ListNode *head) {
    	if(head==NULL || head->next==NULL) return head;
    	ListNode *L = head, *R = head->next;
    	ListNode *pL= head, *pR = head->next;
    	ListNode *p = head->next->next;
    	ListNode result(0);
    	for(int n = 0; p!=NULL; p = p->next, ++n){
    		if(n%2==0){
    			pL->next = p;
    			pL = p;
    		}else{
    			pR->next = p;
    			pR = p;
    		}
    	}
    	pL->next=NULL, pR->next=NULL;
    	pL = sortList(L), pR = sortList(R);
    	p = &result;
    	while(pL!=NULL || pR!=NULL){
    		ListNode *q=NULL;
    		if(pL!=NULL && pR!=NULL){
    			if(pL->val < pR->val){
    				q = pL;
    				pL = pL->next;
    			}else{
    				q = pR;
    				pR = pR->next;	
    			}
    		}else if(pL!=NULL){
    			q = pL;
    			pL = pL->next;
    		}else{
    			q = pR;
    			pR = pR->next;
    		}
    		p->next = q;
    		p = p->next;
    	}
    	p->next = NULL;
    	return result.next;
    }
};

int main(){}
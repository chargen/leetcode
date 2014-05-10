#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void outputList(ListNode *head){
	while(head != NULL){
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
} 

class Solution {
public:
    void reorderList(ListNode *head) {
    	if(head == NULL) return;
    	ListNode *p, *q;
    	p = q = head;
    	while(q->next != NULL){
    		q = q->next;
    		if(q->next != NULL) q = q->next;
    		p = p->next;
    	}
    	ListNode rhead(0);
    	//outputList(p); outputList(q);
    	rhead.next = p->next;
    	p->next = NULL;
    	p = rhead.next;
    	//outputList(head); outputList(rhead.next);
    	rhead.next = NULL;
    	while(p != NULL){
    		ListNode *t = p->next;
    		p->next = rhead.next;
    		rhead.next = p;
    		p = t;
    	}
    	//outputList(rhead.next);
    	p = head, q = rhead.next;
    	while(p != NULL && q != NULL){
    		ListNode *t = q->next;
    		q->next = p->next;
    		p->next = q;
    		p = q->next;
    		q = t;
    	}
    }
};

int main(){
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	sol.reorderList(head);
	outputList(head);
}
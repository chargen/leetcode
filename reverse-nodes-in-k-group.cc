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


void outputList(ListNode *p){
	while(p != NULL){
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
    	ListNode node(0);
    	ListNode *p = head;
    	ListNode *r = &node;
    	bool finished = false;
    	while(finished != true){
    		ListNode *q = p;
    		for(int i = 0; i < k; ++i){
    			if(q != NULL) q = q->next;
    			else{
    				finished = true;
    				break;
    			}
    		}
    		if(finished == false){
    			ListNode *r_new = p;
    			while(p != q){
    				ListNode *t = p->next;
    				p->next = r->next;
    				r->next = p;
    				p = t;
    			}
    			r = r_new;
    		}else
    			r->next = p;
    	}
    	return node.next;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for(int i = 2; i < 4; ++i){
		p->next = new ListNode(i);
		p = p->next;
	}
	Solution sol;
	outputList(head);
	outputList(sol.reverseKGroup(head, 1));
}
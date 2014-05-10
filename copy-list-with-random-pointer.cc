#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 **/
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void outputList(RandomListNode *p){
	while(p!=NULL){
		cout << p->label << "->";
		p = p->next;
	}
	cout << endl;
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode oldList(0), newList(0);
        oldList.next = head;
    	RandomListNode *p, *q;
    	p = oldList.next;
        while(p != NULL){
        	q = p->next;
        	p->next = new RandomListNode(p->label);
        	p->next->random = p->random;
        	p->next->next = q;
        	p = q;
        }
        //outputList(&oldList);
        p = oldList.next;
        while(p != NULL){
        	if(p->next->random != NULL)
        		p->next->random = p->next->random->next;
        	p = p->next->next;
        }
        p = &oldList, q = &newList;
        while(p->next){
        	q->next = p->next->next;
        	p->next->next = p->next->next->next;
        	q = q->next;
        	p = p->next;
        }
        return newList.next;
    }
};

int main(){
	RandomListNode *head = new RandomListNode(-1);
	Solution sol;
	sol.copyRandomList(head);
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
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
	struct Comp{
		bool operator()(const ListNode* a, const ListNode* b){
			return a->val > b->val;
		}
	} comp;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	vector<ListNode*> heap;
    	ListNode head(0), *p;
    	head.next = NULL, p = &head;
        for(int i = 0; i < lists.size(); ++i){
        	if(lists[i] != NULL)
        		heap.push_back(lists[i]);
        }
        make_heap(heap.begin(), heap.end(), comp);
        while(heap.size()){
        	p->next = heap[0];
        	p = heap[0];
        	pop_heap(heap.begin(), heap.end(), comp);
        	heap.pop_back();
        	if(p->next != NULL){
        		heap.push_back(p->next);
        		push_heap(heap.begin(), heap.end(), comp);
        	}
	    }
        return head.next;
    }
};

int main(){
	Solution sol;
	ListNode *p1 = new ListNode(1);
	//p1->next = new ListNode(2);
	//p1->next->next = new ListNode(3);
	ListNode *p2 = new ListNode(3);
	//p2->next = new ListNode(4);
	//p2->next->next = new ListNode(5);
	vector<ListNode*> lists;
	//lists.push_back(p1);
	//lists.push_back(p2);
	lists.push_back(NULL);
	sol.mergeKLists(lists);
	//cout << (sol.mergeKLists(vector<ListNode*>()) == NULL ? "NULL" : "Not NULL") << endl;
}
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

void test(vector<ListNode *> &lists) {
    cout << lists.size() << endl;
    return;
}

int main(){
	ListNode *p1 = new ListNode(1);
	//p1->next = new ListNode(2);
	//p1->next->next = new ListNode(3);
	ListNode *p2 = new ListNode(3);
	//p2->next = new ListNode(4);
	//p2->next->next = new ListNode(5);
	vector<ListNode*> lists;
	lists.push_back(p1);
	lists.push_back(p2);
	lists.push_back(NULL);
	test(lists);
}
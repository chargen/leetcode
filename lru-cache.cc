#include <map>
#include <iostream>
using namespace std;

class LRUCache{
public:
	int capacity;
	struct Node{
		int key, value;
		Node *next, *pre;
	} head, tail;
	map<int, Node*> keyValue;

    LRUCache(int capacity_) {
    	head.pre = NULL, head.next = &tail;
    	tail.pre = &head, tail.next = NULL;
    	capacity = capacity_;
    }
    
    int get(int key) {
        if(keyValue.find(key) != keyValue.end()){
        	Node *p = keyValue[key];
        	remove(p);
        	add(p);
        	return p->value;
        }
        return -1;
    }
    
    void remove(Node* p){
		p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void add(Node* p){
        p->pre = tail.pre;
        p->next = &tail;
        p->pre->next = p;
        p->next->pre = p;
    }

    void set(int key, int value) {
        if( keyValue.find(key) != keyValue.end()){
        	Node *p = keyValue[key];
        	p->value = value;
        	remove(p);
        	add(p);
        }else{
        	if(keyValue.size() == capacity){
        		Node *p = head.next;
        		keyValue.erase(p->key);
        		keyValue[key] = p;
        		p->key = key;
        		p->value = value;
        		remove(p);
        		add(p);
        	}else{
        		Node *p = new Node();
        		keyValue[key] = p;
        		p->key = key;
        		p->value = value;
        		add(p);
        	}
        }
    }
};

int main(){
	LRUCache lruCache(2);
	lruCache.set(2,1);
	lruCache.set(1,1);
	lruCache.set(2,3);
	lruCache.set(4,1);
	cout << lruCache.get(1) << endl;
	cout << lruCache.get(2) << endl;
}
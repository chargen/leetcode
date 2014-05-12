#include <map>
#include <vector>
#include <iostream>
using namespace std;


vector<int> uset, cnt;
map<int, int> hashmap;
int root(int k){
	if(uset[k] == k) return k;
	return uset[k] = root(uset[k]);
}
class Solution {
public:
	void init(int k){
		uset.clear();
		cnt.clear();
		hashmap.clear();
		for(int i = 0; i < k; ++i){
			uset.push_back(i);
			cnt.push_back(1);
		}
	}
	int merge(int aa, int bb){
		int a = hashmap[aa], b = hashmap[bb];
		a = root(a), b = root(b);
		if(a != b) uset[b] = a, cnt[a] += cnt[b];
		return cnt[a];
	}
	void insert(int a){
		if(hashmap.find(a) == hashmap.end())
			hashmap.insert(make_pair(a, hashmap.size()));
	}
    int longestConsecutive(vector<int> &num) {
    	init(num.size());
    	int ans = 1;
    	for(int i = 0; i < num.size(); ++i){
    		int t = num[i];
    		insert(t);
    		if(hashmap.find(t+1) != hashmap.end())
    			ans = max(ans, merge(t, t+1));
    		if(hashmap.find(t-1) != hashmap.end())
    			ans = max(ans, merge(t, t-1));
        }
        return ans;
    }
};

int main(){
	Solution sol;
	cout << INT_MAX << " " << INT_MAX + 1 << endl;
	cout << INT_MIN << " " << INT_MAX - 1 << endl;
	int array[] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
	for(int i = 0; i < 7; ++i){
		cout << array[i] << " " << array[i] - 1 << " " << array[i] + 1 << endl;
	}
	vector<int> num(array, array+sizeof(array)/sizeof(int));
	cout << sol.longestConsecutive(num) << endl;
}
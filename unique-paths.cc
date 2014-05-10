#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<int> pre, cur;
    	pre.push_back(1);
    	for(int i = 1; i <= m+n-2; ++i){
    		cur.clear();
    		cur.push_back(1);
    		for(int j = 1; j < i; ++j)
    			cur.push_back(pre[j-1] + pre[j]);
    		cur.push_back(1);
    		pre.swap(cur);
    	}
    	return pre[m-1];
    }
};

int main(){
	Solution sol;
	cout << sol.uniquePaths(1, 10) << endl;
	cout << sol.uniquePaths(1, 2) << endl;
}
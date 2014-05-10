#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	vector<vector<int> > ans;
    	vector<int> tmp(4, 0);
    	int n = num.size(), m = 0;
    	sort(num.begin(), num.end());
    	for(int k = 0; k < n; ++k){
    		tmp[0] = num[k];
    		if(k > 0 && num[k] == num[k-1]) continue;
	    	for(int i = k + 1; i < n; ++i){
	    		if(i > k + 1 && num[i] == num[i-1]) continue;
	    		int f = i + 1, r = n - 1;
	    		tmp[1] = num[i];
	    		int start = m;
	    		while(f < r){
	    			if(num[f] + num[r] == target-num[k]-num[i]){
	    				tmp[2] = num[f], tmp[3] = num[r];
	    				sort(tmp.begin(), tmp.end());
	    				if(m == start || tmp[2] != ans[m-1][2] || tmp[3] != ans[m-1][3]){
	    					ans.push_back(tmp);
	    					++m;
	    				}
	    				++f, --r;
	    			}else if(num[f] + num[r] > target-num[k]-num[i])
	    				--r;
	    			else if(num[f] + num[r] < target-num[k]-num[i])
	    				++f;
	    		}
	    	}
    	}
    	return ans;        
    }
};

int main(){
	Solution sol;
	int array[] = {0, 0, 0, 0};
	vector<int> num(array, array+sizeof(array)/sizeof(int));
	auto ans = sol.fourSum(num, 0);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
	cout << ans.size() << endl;
}
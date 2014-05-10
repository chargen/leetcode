#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > ans;
    	vector<int> tmp(3, 0);
    	int n = num.size(), m = 0;
    	sort(num.begin(), num.end());
    	for(int i = 0; i < n; ++i){
    		if(i > 0 && num[i] == num[i-1]) continue;
    		int f = i + 1, r = n - 1;
    		while(f < r){
    			if(num[f] + num[r] == -num[i]){
    				tmp[0] = num[i], tmp[1] = num[f], tmp[2] = num[r];
    				sort(tmp.begin(), tmp.end());
    				if(m == 0 || tmp[1] != ans[m-1][1] || tmp[2] != ans[m-1][2]){
    					ans.push_back(tmp);
    					++m;
    				}
    				++f, --r;
    			}else if(num[f] + num[r] > -num[i])
    				--r;
    			else if(num[f] + num[r] < -num[i])
    				++f;
    		}
    	}
    	return ans;
    }
};

int main(){
	Solution sol;
	//int array[] = {-1,0,1,2,-1,-4};
	int array[] = {0, 0, 0, 0, 0};
	//int array[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};/**/
	vector<int> num(array, array+sizeof(array)/sizeof(int));
	auto ans = sol.threeSum(num);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	cout << ans.size() << endl;
}
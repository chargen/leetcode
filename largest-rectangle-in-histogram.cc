#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	vector<pair<int, int>> ss;
    	int n = height.size(), ans = 0;
    	for(int i = 0; i < n; ++i){
    		if(i==0 || height[i]>height[ss.back().first])
    			ss.push_back(make_pair(i, i));
    		else{
    			while(ss.size()>0 && height[i]<=height[ss.back().first]){
    				ans = max(ans, height[ss.back().first]*(i-ss.back().second));
    				ss.pop_back();
    			}
    			if(ss.size() == 0) ss.push_back(make_pair(i, 0));
    			else ss.push_back(make_pair(i, ss.back().first+1));
    		}
    	}
    	while(ss.size()>0){
    		ans = max(ans, height[ss.back().first]*(n-ss.back().second));
    		ss.pop_back();
    	}
    	return ans;
    }
};

int main(){
	int array[] = {4,2,0,3,2,5};
	vector<int> height(array, array+sizeof(array)/sizeof(int));
	Solution sol;
	cout << sol.largestRectangleArea(height) << endl;
}
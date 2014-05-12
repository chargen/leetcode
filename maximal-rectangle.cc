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
    int maximalRectangle(vector<vector<char> > &matrix) {
    	int ans = 0;
    	if(matrix.size()){
    		int m = matrix.size(), n = matrix[0].size();
    		vector<int> height(n, 0);
    		for(int i = 0; i < m; ++i){
    			for(int j = 0; j < n; ++j)
    				if(matrix[i][j] == '1') ++height[j];
    				else height[j] = 0;
    			ans = max(ans, largestRectangleArea(height));
    		}
    	}
    	return ans;
    }
};

int main(){
	char matrixChar[][6]={"01101","11010","01110","11110","11111","00000"};
	vector<vector<char> > matrix;
	for(int i = 0; i < 6; ++i)
		matrix.push_back(vector<char>(matrixChar[i], matrixChar[i]+5));
	Solution sol;
	cout << sol.maximalRectangle(matrix) << endl;
}
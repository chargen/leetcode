class Solution {
public:
    int numTrees(int n) {
    	vector<int> ans;
    	ans.push_back(1);
    	ans.push_back(1);
    	for(int i = 2; i <= n; ++i){
    		ans.push_back(0);
    		for(int j = 0; j <= i - 1; ++j){
    			ans[i] += ans[j] * ans[i-1-j];
    		}
    	}
    	return ans[n];
    }
};
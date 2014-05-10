#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > ans;
	vector<int>tmp;

	void dfs(vector<int> &candidates, int k, int target){
		if(target == 0){
			ans.push_back(tmp);
			return;
		}
		if(k == -1) return;
		int size = tmp.size();
		for(int t = target; t >=0 ; t -= candidates[k]){
			dfs(candidates, k-1, t);
			tmp.push_back(candidates[k]);
		}
		tmp.resize(size);
		return;
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tmp.clear();
        ans.clear();
        dfs(candidates, candidates.size() - 1, target);
        for(int i = 0; i < ans.size(); ++i)
        	sort(ans[i].begin(), ans[i].end());
        return ans;
    }
};

int main(){
	int array[] = {2,3,6,7};
	vector<int> candidates(array, array + 4);
	Solution sol;
	auto ans = sol.combinationSum(candidates, 7);
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
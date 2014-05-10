#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > ans;
	vector<int> tmp;

	void dfs(vector<pair<int, int> > &candidates, int k, int target){
		if(target == 0){
			ans.push_back(tmp);
			return;
		}
		if(k == -1) return;
		int size = tmp.size();
		for(int i = 0; i <= candidates[k].second; ++i){
			if(target >= 0){
				dfs(candidates, k-1, target);
				tmp.push_back(candidates[k].first);
			}else
				break;
			target -= candidates[k].first;
		}
		tmp.resize(size);
		return;
	}
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    	vector<pair<int, int> > newCandidates;
    	sort(candidates.begin(), candidates.end());
    	for(int i = 0, j = 0; i < candidates.size(); ){
    		for(j = i; j < candidates.size(); ++j){
    			if(candidates[j] != candidates[i])
    				break;
    		}
    		newCandidates.push_back(make_pair(candidates[i], j-i));
    		i = j;
    	}
        tmp.clear();
        ans.clear();
        dfs(newCandidates, newCandidates.size() - 1, target);
        for(int i = 0; i < ans.size(); ++i)
        	sort(ans[i].begin(), ans[i].end());
        return ans;
    }
};

int main(){
	int array[] = {10,1,2,7,6,1,5};
	vector<int> candidates(array, array + 7);
	Solution sol;
	auto ans = sol.combinationSum2(candidates, 8);
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
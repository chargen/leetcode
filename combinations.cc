#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:

	vector<int> tmp;
	vector<vector<int> > ans;
	void combine_(int t, int n, int k){
		if(tmp.size() == k){
			ans.push_back(tmp);
			return;
		}
		for(int i = t; i <= n; ++i){
			tmp.push_back(i);
			combine_(i+1, n, k);
			tmp.pop_back();
		}
	}

    vector<vector<int> > combine(int n, int k) {
    	ans.clear();
    	tmp.clear();
    	combine_(1, n, k);
    	return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<int> > ans = sol.combine(4, 2);
	for(int i = 0; i < ans.size(); ++i){
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	vector<vector<int> > ans;
    	vector<int> perm(num);
    	sort(perm.begin(), perm.end());
    	ans.push_back(perm);
    	while(true){
    		int pos, n = perm.size();
    		for(pos = n-1; pos>0; --pos){
    			if(perm[pos-1]<perm[pos])
    				break;
    		}
    		if(pos == 0) break;
    		int minpos = pos;
    		for(int i = pos; i < n; ++i){
    			if(perm[i]>perm[pos-1] && perm[i] < perm[minpos])
    				minpos = i;
    		}
    		int tmp = perm[pos-1];
    		perm[pos-1] = perm[minpos];
    		perm[minpos] = tmp;
    		sort(perm.begin()+pos, perm.end());
    		ans.push_back(perm);
    	}
    	return ans;     
    }
};

int main(){
	int array[] = {1,2,3,4};
	vector<int> perm(array, array + 4);
	Solution solution;
	vector<vector<int> > ans = solution.permute(perm);
	for(int i = 0; i < ans.size(); ++i){
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << ans.size() << endl;
}
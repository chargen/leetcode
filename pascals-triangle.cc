#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> row[2];
        vector<vector<int> > ans;
        if(numRows){
            row[0].push_back(1);
            int pre = 0, cur = 1;
            ans.push_back(row[pre]);
            for(int i = 1; i < numRows; ++i){
            	row[cur].clear();
            	row[cur].push_back(1);
            	for(int j = 1; j <i; ++j)
            		row[cur].push_back(row[pre][j] + row[pre][j-1]);
            	row[cur].push_back(1);
    	        ans.push_back(row[cur]);
            	cur ^= 1, pre ^= 1;
            }
        }
        return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<int> > res = sol.generate(1);
	for(int i = 0; i < res.size(); ++i){
		copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row[2];
        row[0].push_back(1);
        int pre = 0, cur = 1;
        for(int i = 1; i <= rowIndex; ++i){
        	row[cur].clear();
        	row[cur].push_back(1);
        	for(int j = 1; j <i; ++j)
        		row[cur].push_back(row[pre][j] + row[pre][j-1]);
        	row[cur].push_back(1);
        	cur ^= 1, pre ^= 1;
        }
        return row[pre];
    }
};

int main(){
	Solution sol;
	vector<int> res = sol.getRow(3);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> ans;
    	for(int i = 0; i < (1<<n); ++i)
    		ans.push_back((i>>1)^i);
    	return ans;        
    }
};

int main(){
	Solution sol;
	auto ans = sol.grayCode(2);
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
}
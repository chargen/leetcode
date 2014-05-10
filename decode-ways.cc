#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    	int len = s.length();
    	if(len == 0) return 0;
    	vector<int> ans(len+1, 0);
    	ans[0] = 1;
    	ans[1] = ((s[0] == '0') ? 0 : 1);
    	for(int i = 1; i < len; ++i){
    		ans[i+1] = 0;
    		if(s[i] != '0') ans[i+1] += ans[i];
    		if(s[i-1] == '1' || s[i-1]=='2' && s[i] <='6')
    			ans[i+1] += ans[i-1];
    	}
    	return ans[len];
    }
};

int main(){
	Solution sol;
	cout << sol.numDecodings("10") << endl;
}
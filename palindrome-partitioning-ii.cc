#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
    	int len = s.length();
    	vector<bool> dp(len*len, false);
    	#define dp(x, y) dp[(x)*len+y]
    	for(int i = 0; i < len; ++i){
    		dp(i, i) = true;
    		if(i+1<len && s[i] == s[i+1]) dp(i, i+1) = true;
    	}
    	for(int d = 3; d <= len; ++ d){
	    	for(int i = 0; i + d <= len; ++i){
    			int l = i, r = i + d - 1;
    			if(s[l] == s[r] && dp(l+1, r-1) == true){
    				dp(l, r) = true;
    				//cout << s.substr(l, d) << endl;
    			}
    		}
    	}
    	vector<int> status(len, 0x3f3f3f3f);
    	for(int i = 0; i < len; ++i){
    		if(dp(0, i)) status[i] = 0;
    		for(int j = 0; j < i; ++j){
    			if(dp(j+1,i))
                    status[i] = min(status[i], status[j] + 1);
    		}
    	}
    	return status[len-1];
    }
};

int main(){
	Solution sol;
	string s = "aab";
	cout << sol.minCut(s) << endl;
}
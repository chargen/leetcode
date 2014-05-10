#include <string>
#include <iostream>
using namespace std;

bool dp[1024][1024];
class Solution {
public:
    string longestPalindrome(string s) {
    	memset(dp, false, sizeof(dp));
    	int len = s.length();
    	int maxLen = 1, start = 0;
    	for(int i = 0; i < len; ++i)
    		dp[i][i] = true;
    	for(int i = 0; i+1 < len; ++i)
    		if(s[i] == s[i+1]){
    			dp[i][i+1] = true;
    			maxLen = 2, start = i;
    		}
    	for(int k = 3; k <= len; ++k){
    		for(int i = 0; i + k - 1 < len; ++i){
    			if(s[i] == s[i+k-1] && dp[i+1][i+k-2]){
    				dp[i][i+k-1] = true;
    				maxLen = k, start = i;
    			}
    		}
    	}
    	return s.substr(start, maxLen);
    }
};

int main(){
	Solution sol;
	cout << sol.longestPalindrome(string("abbcbcbab")) << endl;
}
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int hash[300]={0};
    	int l=0, r=0, len = s.length();
    	int ans = 0;
    	while(r < len){
    		while(r < len && hash[s[r]] == 0){
    			hash[s[r]] = 1;
    			++r;
    		}
    		ans = max(ans, r - l);
    		while(l < r && s[l] != s[r]){
    			hash[s[l]] = 0;
    			++l;
    		}
    		hash[s[r]] = 0;
    		++l;
    	}
    	return ans;
    }
};

int main(){
	Solution sol;
	cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
	cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << sol.lengthOfLongestSubstring("abc") << endl;
}
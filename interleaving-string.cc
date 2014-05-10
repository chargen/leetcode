#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    	if(n1 + n2 != n3) return false;
    	vector<bool> dp((n1+1)*(n2+1), false);
    	#define dp(x, y) dp[(x)*(n2+1)+y]
    	dp(0, 0) = true;
    	for(int i = 0; i < n1; ++i)
    		if(dp(i, 0) && s1[i] == s3[i])
    			dp(i+1, 0) = true;
    	for(int i = 0; i < n2; ++i)
    		if(dp(0, i) && s2[i] == s3[i])
    			dp(0, i+1) = true;
    	for(int i = 0; i < n1; ++i){
    		for(int j = 0; j < n2; ++j){
    			if(dp(i+1, j+1) == false){
    				for(int s = j, t = i+j+1; s >= 0;--s, --t){
    					if(s2[s] == s3[t]){
    						dp(i+1, j+1) = dp(i+1, s);
    						if(dp(i+1, j+1)) break;
    					}else
    						break;
    				}
    			}
    			if(dp(i+1, j+1) == false){
    				for(int s = i, t = i+j+1; s >= 0;--s, --t){
    					if(s1[s] == s3[t]){
    						dp(i+1, j+1) = dp(s, j+1);
    						if(dp(i+1, j+1)) break;
    					}else
    						break;
    				}
    			}
    		}
    	}
    	return dp(n1, n2);
    }
};

int main(){
	Solution sol;
	cout << (sol.isInterleave("a", "b", "ab") ? "true" : "false") << endl;
	cout << (sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") ? "true" : "false") << endl;
	cout << (sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") ? "true" : "false") << endl;
}
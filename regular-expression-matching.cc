#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	int ns = strlen(s), np = strlen(p);
    	vector<bool> dp((ns+1) * (np+1), false);
    	#define dp(i, j) dp[(i)*(np+1) + j]
    	dp(0, 0) = true;
    	for(int i = 0; i < np; ++i){
    		if(i + 1 < np && p[i + 1] == '*' ){
    			dp(0, i+2) = dp(0, i);
    			++i;
    		}
    	}
    	for(int i = 0; i < ns; ++i){
    		for(int j = 0; j < np; ++j){
    			if(j + 1 <np && p[j + 1] == '*'){
    				if(dp(i+1,j) == true)
    					dp(i+1, j+2) = true;
    				else{
    					for(int k = i; k>= 0; --k){
    						if(p[j] == '.' || s[k] == p[j]){
    							dp(i+1, j+2) = dp(k, j);
    							if(dp(i+1, j+2)) break;
    						}else if(s[k] != p[j])
    							break;
    					}
    				}
    				++j;
    			}else if(p[j] == '.' || s[i] == p[j])
    				dp(i+1, j+1) = dp(i, j);
    		}
    	}
    	cout << s << " " << p << " "<< (dp(ns, np)? "Yes" : "No") << endl;
    	return dp(ns, np);
    }
};

int main(){
	Solution sol;
	sol.isMatch("aa", "aa");
	sol.isMatch("aa", "a*");
	sol.isMatch("aa", "..");
	sol.isMatch("ab", "a*");
}
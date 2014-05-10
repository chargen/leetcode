#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	int ns = strlen(s);
    	int np = strlen(p);
    	int minlen = 0;
    	for(int i = 0; i < np; ++i)
    		if(p[i] != '*')
    			++minlen;
   		if(minlen > ns) return false;
    	vector<bool> dp((ns+1)*(np+1), false);
    	// dp(i, j) -  Is s[0..i) matched with p[0..j)
    	#define dp(x, y) dp[(x)*(np+1) + y]
    	dp(0, 0) = true;
        for(int i = 0; i < np; ++i)
            if(p[i] == '*')
                dp(0, i+1) = dp(0, i);
    	for(int i = 0; i < ns; ++i){
    		for(int j = 0; j < np; ++j){
    			if(p[j] == '?'){
    				dp(i+1, j+1) = dp(i, j); 
    			}else if(p[j] == '*'){
    				dp(i+1, j+1) = (dp(i, j+1) || dp(i+1, j));
    			}else if(p[j] == s[i]){
    				dp(i+1, j+1) = dp(i, j);
    			}else dp(i+1, j+1) = false;
    		}
    	}
        /*for(int i = 0; i <= ns; ++i){
            for(int j = 0; j <= np; ++j){
                cout << dp(i, j) << " ";
            }
            cout << endl;
        }*/
    	return dp(ns, np);
    }
};

int main(){
	Solution sol;
	cout << (sol.isMatch("aa", "*") ? "true" : "false") << endl;
	//cout << (sol.isMatch("aabbbabaaaaaabbabbaabbabbbabaabaaabbbabbabbbbababbabaaaaaabaabaabbbababaaabbaabaaabaabaabaaabaaababbaabababbabbababbbbabbababbbababaaaabaabbbabababaabbbaaababbbbbbbbabaaabbaabbbaababaaaababababbabbbbbb", "a*bab***b**abbabaa**a*a**b****b*b*****b*bb***a**a**a***baba*abbbaa***bb**bbabb*b*b*bab*a****a*bb*a**b") ? "true" : "false") << endl;
}
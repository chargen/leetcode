class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	int len = s.length();
    	vector<bool> dp(len+1, false);
    	dp[0] = true;
    	for(int i = 0; i < len; ++i){
    		for(int j = 0; j <= i; ++j){
    			if(dp[j]){
    				string t = s.substr(j, i-j+1);
    				if(dict.find(t) != dict.end())
    					dp[i+1] = true;
    			}
    		}
    	}
    	return dp[len];
    }
};
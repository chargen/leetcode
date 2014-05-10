class Solution {
public:
    int minDistance(string word1, string word2) {
    	int n1 = word1.length(), n2 = word2.length();
    	vector<int> dp((n1+1)*(n2+1), 0x3f3f3f3f);
    	#define dp(i, j) dp[(i)*(n2+1)+j]
    	dp(0, 0) = 0;
    	for(int i = 0; i < n1; ++i) dp(i+1, 0) = i+1;
    	for(int i = 0; i < n2; ++i) dp(0, i+1) = i+1;
    	for(int i = 0; i < n1; ++i){
    		for(int j = 0; j < n2; ++j){
    			int d;
    			dp(i+1, j+1) = min(dp(i+1,j)+1, dp(i+1, j+1));
    			dp(i+1, j+1) = min(dp(i,j+1)+1, dp(i+1, j+1));
    			if(word1[i] == word2[j]) d = 0;
    			else d = 1;
    			dp(i+1, j+1) = min(dp(i,  j)+d, dp(i+1, j+1));
    		}
    	}
    	return dp(n1, n2);
    }
};
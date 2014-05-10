class Solution {
public:
    int climbStairs(int n) {
    	vector<int> f;
    	f.push_back(1);
    	f.push_back(1);
    	for(int i = 2; i <= n; ++i)
    		f.push_back(f[i-2]+f[i-1]);
    	return f[n];
    }
};
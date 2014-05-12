class Solution {
public:
    vector<int> dp;
    #define dp(x, y, z) dp[((x)*n+y)*n+z]
    #define DFS(x, y, z) dfs(s1, s2, x, y, z)
    int n;
    int dfs(string& s1, string& s2, int p1, int p2, int len){
        if(dp(p1, p2, len) != -1) return dp(p1, p2, len);
        if(len == 1) return s1[p1] == s2[p2] ? 1 : 0;
        dp(p1, p2, len) = 0;
        for(int i = 1; i < len; ++i){
            int d =((dfs(p1, p2, i) & dfs(p1+i, p2+i, len-i)) |
                    (dfs(p1, p2+len-i, i) & dfs(p1+i, p2, len-i)));
            dp(p1, p2, len) = d;
            if(d == 1) return 1;
        }
        return 0;
    }
    bool isScramble(string s1, string s2) {
        n = s1.length();
        dp.resize((n+1)*(n+1)*(n+1), -1);
        return DFS(0, 0, n);
    }
};

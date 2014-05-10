class Solution {
public:
	vector<string> ans;
	vector<char> ss;
	void dfs(int l, int r, int n){
		if(l == n && r == n){
			string tmp = "";
			for(int i = 0; i < 2*n; ++i) tmp += ss[i];
			ans.push_back(tmp);
			return;
		}
		if(l < r) return;
		if(l < n){
			ss.push_back('(');
			dfs(l+1, r, n);
			ss.pop_back();
		}
		if(r < l){
			ss.push_back(')');
			dfs(l, r+1, n);
			ss.pop_back();
		}
	}
    vector<string> generateParenthesis(int n) {
    	ans.clear();
    	ss.clear();
    	dfs(0, 0, n);
    	return ans;
    }
};
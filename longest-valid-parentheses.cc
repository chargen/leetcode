class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<pair<char, int> > ss;
    	ss.push(make_pair(')', -1));
    	for(int i = 0; i < s.length(); ++i){
    		if(s[i] == '(') ss.push(make_pair('(', i));
    		else{
    			if(ss.top().first == '(') ss.pop();
    			else ss.push(make_pair(')', i));
    		}
    	}
    	int ans = 0;
    	for(int p1 = s.length(); ss.size() > 0; ){
    		int p2 = p1;
    		p1 = ss.top().second;
    		ss.pop();
    		ans = max(ans, p2 - p1 - 1);
    	}
    	return ans;
    }
};
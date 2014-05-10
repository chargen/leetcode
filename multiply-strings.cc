class Solution {
public:
    string multiply(string num1, string num2) {
    	vector<int> a, b;
    	for(int i = num1.size() -1; i >= 0; --i)
    		a.push_back(num1[i] - '0');
    	for(int i = num2.size() -1; i >= 0; --i)
    		b.push_back(num2[i] - '0');
    	vector<int> c(a.size() + b.size(), 0);
    	for(int i = 0; i < a.size(); ++i)
    		for(int j = 0; j < b.size(); ++j)
    			c[i+j] += a[i] * b[j];
    	for(int i = 0; i < c.size(); ++i)
    		if(c[i] >= 10){
    			c[i+1] += c[i] / 10;
    			c[i] %= 10;
    		}
    	string ans = "";
    	for(int i = c.size() - 1; i >= 0; --i){
    		if(i > 0 && c[i] == 0 && ans.size() == 0) continue;
    		else ans += c[i] + '0';
    	}
    	return ans;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
    	reverse(a.begin(), a.end());
    	reverse(b.begin(), b.end());
    	string ans = "";
    	int carry = 0;
    	for(int i = 0; i < a.size() || i < b.size(); ++i){
    		if(i < a.size()) carry += a[i] - '0';
    		if(i < b.size()) carry += b[i] - '0';
    		ans += (carry % 2) + '0';
    		carry /= 2;
    	}
    	if(carry) ans += '1';
    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};
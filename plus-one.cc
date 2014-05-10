class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	int len = digits.size();
    	int carry = 1;
    	vector<int> ans(digits);
    	for(int i = len - 1; i >= 0; --i){
    		ans[i] = (ans[i] + carry);
    		carry = ans[i] / 10;
    		ans[i] = ans[i] % 10;
    	}
    	if(carry)
    		ans.insert(ans.begin(), carry);
    	return ans;
    }
};
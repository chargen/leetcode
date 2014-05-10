class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int n = prices.size();
    	vector<int> L(n, 0);
    	vector<int> R(n, 0);
    	int ans = 0;
    	if(n){
	    	for(int i = 1, min_price = prices[0]; i < n; ++i){
	    		L[i] = max(L[i-1], prices[i] - min_price);
	    		ans = max(ans, L[i]);
	    		if(min_price > prices[i])
	    			min_price = prices[i];
	    	}
	    	for(int i = n-2, max_price = prices[n-1]; i >= 0; --i){
	    		R[i] = max(R[i+1], max_price - prices[i]);
	    		ans = max(ans, R[i]);
	    		if(max_price < prices[i])
	    			max_price = prices[i];
	    	}
	    	for(int i = 1; i < n; ++i)
    			ans = max(L[i-1] + R[i], ans);
    	}
    	return ans;
    }
};
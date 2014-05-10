class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int result = 0;
    	for(int i = 0, low = 0; i < prices.size(); ++i){
    		if(i > 0)
    			result = max(result, prices[i] - low);
    		if(i == 0 || prices[i] < low)
    			low = prices[i];
    	}
    	return result;
    }
};
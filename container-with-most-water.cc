class Solution {
public:
    int maxArea(vector<int> &height) {
    	int maxAreaValue = 0;
    	int f = 0, r = height.size() - 1;
    	while(f < r){
    		maxAreaValue = max(maxAreaValue, min(height[f], height[r])*(r-f));
    		if(height[f] > height[r]) --r;
    		else ++f;
    	}
    	return maxAreaValue;
    }
};
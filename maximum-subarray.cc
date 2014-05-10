class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int ans = A[0];
    	for(int i = 0, curSum = 0, minSum = 0;
    		i < n;
    		++i){
    		curSum += A[i];
    		if(i == 0){
    			minSum = curSum;
    		}else{
    			if(curSum > ans) ans = curSum;
	    		if(curSum - minSum > ans) ans = curSum - minSum;
	    		if(curSum < minSum) minSum = curSum;
	    	}
    	}
    	return ans;
    }
};
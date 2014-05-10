class Solution {
public:
    bool canJump(int A[], int n) {
    	vector<bool>int(n, false);
    	canReach[0] = true;
    	for(int i = 0; i < n; ++i){
    		if(canReach[i]){
	    		int v = A[i];
	    		for(int j = 1; j<= v && i+j<n; ++j){
	    			canReach[i+j] = true;
	    			if(canReach[n-1]) break;
	    		}
	    	}
    	}
    	return canReach[n-1];
    }
};
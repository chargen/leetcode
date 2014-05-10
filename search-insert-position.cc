class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if(A[n-1] < target) return n;
    	int l = -1, r = n-1;
    	while(l+1 < r){
    		int mid = (l+r)/2;
    		if(A[mid] >= target)
    			r = mid;
    		else
    			l = mid;
    	}
    	return r;
    }
};
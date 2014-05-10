class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	int l, r;
    	vector<int> ans;
		l = -1, r = n-1;
    	while(l+1<r){
    		int mid = (l+r)/2;
    		if(A[mid] < target)
    			l = mid;
    		else
    			r = mid;
    	}
    	if(A[r] == target) ans.push_back(r);
    	else ans.push_back(-1);
    	l = 0, r = n;
    	while(l+1<r){
    		int mid = (l+r)/2;
    		if(A[mid] <= target)
    			l = mid;
    		else
    			r = mid;
    	}
    	if(A[l] == target) ans.push_back(l);
    	else ans.push_back(-1);
    	return ans;
    }
};
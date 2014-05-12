class Solution {
public:
    bool canJump(int A[], int n) {
        int rightMost = 0;
        for(int i = 0; i < n; ++i)
            if(rightMost >= i)
                rightMost = max(rightMost, i + A[i]);
    	return rightMost >= n-1;
    }
};
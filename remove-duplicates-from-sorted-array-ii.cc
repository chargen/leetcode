class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	int len = 0;
    	for(int i = 0; i < n; ++i)
    		if(len < 2 || A[i] != A[len-2])
    			A[len++] = A[i];
    	return len;
    }
};
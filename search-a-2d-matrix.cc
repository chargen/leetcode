class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	int m = matrix.size(), n = matrix[0].size();
    	int l = 0, r = m;
    	if(matrix[0][0] > target)
    		return false;
    	if(matrix[m-1][n-1] < target)
    		return false;
    	while(l+1<r){
    		int mid = (l+r)/2;
    		if(matrix[mid][0] <= target)
    			l = mid;
    		else
    			r = mid;
    	}
    	int row = l;
    	l = 0, r = n;
    	while(l + 1 < r ){
    		int mid = (l+r)/2;
    		if(matrix[row][mid] <= target)
    			l = mid;
    		else
    			r = mid;
    	}
    	return matrix[row][l] == target;
    }
};
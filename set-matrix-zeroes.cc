class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	int m = matrix.size(), n = matrix[0].size();
    	int sx = -1, sy = -1;
    	for(int i = 0; i < m; ++i)
    		for(int j = 0; j < n; ++j)
    			if(matrix[i][j] == 0) sx = i, sy = j;
    	if(sx == -1) return;
    	for(int i = 0; i < m; ++i){
    		if(matrix[i][sy] == 0) matrix[i][sy] = 1;
    		else matrix[i][sy] = 0;
    	}
    	for(int i = 0; i < n; ++i){
    		if(matrix[sx][i] == 0) matrix[sx][i] = 1;
    		else matrix[sx][i] = 0;
    	}
    	for(int i = 0; i < m; ++i){
    		if(i == sx) continue;
    		for(int j = 0; j < n; ++j){
    			if(j == sy) continue;
    			if(matrix[i][j] == 0){
    				matrix[i][sy] = 1;
    				matrix[sx][j] = 1;
    			}
    		}
    	}
    	for(int i = 0; i < m; ++i){
    		if(i == sx) continue;
    		for(int j = 0; j < n; ++j){
    			if(j == sy) continue;
    			if(matrix[i][sy] == 1 or matrix[sx][j] == 1)
    				matrix[i][j] = 0;
    		}
    	}
    	for(int i = 0; i < m; ++i)
    		matrix[i][sy] = 0;
    	for(int i = 0; i < n; ++i)
    		matrix[sx][i] = 0;
    }
};
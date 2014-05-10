class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	vector<int> pre(n, 0);
    	vector<int> cur(n, 0);
    	pre[0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
    	for(int i = 1; i < n; ++i)
	    	pre[i] = (obstacleGrid[0][i] == 0 ? pre[i-1] : 0);
	    for(int i = 1; i < m; ++i){
	    	cur[0] = (obstacleGrid[i][0] == 0 ? pre[0] : 0);
	    	for(int j = 1; j < n; ++j)
	    		cur[j] = (obstacleGrid[i][j] == 0 ? cur[j-1] + pre[j] : 0);
	    	cur.swap(pre);
	    }
	    return pre[n-1];
    }
};
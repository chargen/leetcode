class Solution {
public:
	vector<bool> visited;
	int n, m;
    bool exist(vector<vector<char> > &board, string word) {
    	if(word.size() == 0) return true;
    	n = board.size();
    	if(n){
    		m = board[0].size();
    		visited.resize(n*m, false);
    		#define visited(x, y) visited[(x)*m+y]
    		for(int i = 0; i < n; ++i){
    			for(int j = 0; j < m; ++j){
    				if(board[i][j] == word[0]){
    					visited(i, j) = true;
    					if(dfs(board, word, i, j, 0) == true) return true;
    					visited(i, j) = false;
    				}
    			}
    		}
    	}
    	return false;
    }

	bool dfs(vector<vector<char> > &board, string& word, int x, int y, int k){
		static int dx[] = {-1, 0, 1, 0};
		static int dy[] = { 0,-1, 0, 1};
		if(k+1 == word.size()) return true;
		for(int i = 0; i < 4; ++i){
			int xx = dx[i] + x, yy = dy[i] + y;
			if(xx >= 0 && xx < n && yy >=0 && yy < m
				&& board[xx][yy] == word[k+1]
				&& visited(xx, yy) == false){
				visited(xx, yy) = true;
				if(dfs(board, word, xx, yy, k+1))return true;
				visited(xx, yy) = false;
			}
		}
		return false;
	}
};
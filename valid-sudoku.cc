class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
    	bool hashRow[9][10] = {false};
    	bool hashCol[9][10] = {false};
    	bool hashBlock[3][3][10] = {false};
    	if(board.size() != 9) return false;
    	for(int i = 0; i < 9; ++i){
    		if(board[i].size() != 9) return false;
    		for(int j = 0; j < 9; ++j){
    			if(board[i][j] != '.'){
    				int d = board[i][j] - '0';
    				if(d < 1 || d > 9) return false;
    				if(hashRow[i][d]) return false;
    				if(hashCol[j][d]) return false;
    				if(hashBlock[i/3][j/3][d])	return false;
    				hashRow[i][d] = true;
    				hashCol[j][d] = true;
    				hashBlock[i/3][j/3][d] = true;
    			}
    		}
    	}
    	return true;
    }
};
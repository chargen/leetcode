#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	if(board.size() == 0) return;
    	int m = board.size(), n = board[0].size();
    	vector<pair<int, int> > Q;
    	vector<bool> H(m*n, false);
    	#define H(x, y) H[(x)*n+y]
    	for(int i = 0; i < m; ++i){
    		if(board[i][0] == 'O' && H(i, 0) == false){
    			Q.push_back(make_pair(i, 0));
    			H(i, 0) = true;
    		}
    		if(board[i][n-1] == 'O' && H(i, n-1) == false){
    			Q.push_back(make_pair(i, n-1));
    			H(i, n-1) = true;	
    		}
    	}
    	for(int i = 0; i < n; ++i){
    		if(board[0][i] == 'O' && H(0, i) == false){
    			Q.push_back(make_pair(0, i));
    			H(0, i) = true;
    		}
    		if(board[m-1][i] == 'O' && H(m-1, i) == false){
    			Q.push_back(make_pair(m-1, i));
    			H(m-1, i) = true;
    		}
    	}
    	int dx[] = {-1, 0, 1, 0}, dy[] = { 0,-1, 0, 1};
    	for(int i = 0; i < Q.size(); ++i){
    		int x = Q[i].first, y = Q[i].second;
    		for(int k = 0; k < 4; ++k){
    			int xx = x + dx[k], yy = y + dy[k];
    			if(xx >= 0 && xx < m && yy >= 0 && yy < n
    				&& board[xx][yy] == 'O' && H(xx, yy) == false){
    				H(xx, yy) = true;
    				Q.push_back(make_pair(xx, yy));
    			}
    		}
    	}
    	for(int i = 0; i < m; ++i)
    		for(int j = 0; j < n; ++j)
    			if(board[i][j] == 'O' && H(i, j) == false){
    				board[i][j] = 'X';
    			}
    	return;
    }
};

int main(){
	Solution sol;
	vector<vector<char> > board;
	char boardChar [][4]={
		"XOX",
		"OXO",
		"XOX"
		/*"OXO",
		"XOX",
		"OXO"*/
	};
	for(int i = 0; i < 3; ++i){
		string s = boardChar[i];
		board.push_back(vector<char>(s.begin(), s.end()));
	}
	sol.solve(board);
	for(int i = 0; i < board.size(); ++i){
		for(int j = 0; j < board[0].size(); ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
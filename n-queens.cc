#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string> > ans;
   	vector<int> colIndex;
	void tryNth(int n, int k){
		if(n == k){
			vector<string> chessBoard;
			chessBoard.resize(n);
			for(int i = 0; i < n; ++i){
				chessBoard[i].resize(n);
				for(int j = 0; j < n; ++j){
					chessBoard[i][j] = '.';
					if(j == colIndex[i])
						chessBoard[i][j] = 'Q';
				}
			}
			ans.push_back(chessBoard);
			return;
		}
		for(int i = 0; i < n; ++i){
			bool valid = true;
			for(int j = 0; j < k; ++j){
				if(i == colIndex[j] || abs(i - colIndex[j]) == k - j){
					valid = false;
					break;
				}
			}
			if(valid){
				colIndex[k] = i;
				tryNth(n, k+1);
			}
		}
	}

    vector<vector<string> > solveNQueens(int n) {
    	colIndex.resize(n);
    	ans.clear();
    	tryNth(n, 0);
    	return ans;
    }
};

int main(){
	Solution sol;
	auto ans = sol.solveNQueens(8);
	cout << ans.size() << endl;
}
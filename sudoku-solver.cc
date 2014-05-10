#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hashRow[9][10];
    bool hashCol[9][10];
    bool hashBlock[3][3][10];
    bool dfs(vector<vector<char> > &board, int x, int y){
        if(y == 9) x = x + 1, y = 0;
        if(x == 9) return true;
        if(board[x][y] == '.'){
            for(int i = 1; i <= 9; ++i){
                if(hashRow[x][i] == false &&
                   hashCol[y][i] == false &&
                   hashBlock[x/3][y/3][i] == false){
                    board[x][y] = i + '0';
                    hashRow[x][i] = true;
                    hashCol[y][i] = true;
                    hashBlock[x/3][y/3][i] = true;               
                    if(dfs(board, x, y+1)) return true;
                    hashRow[x][i] = false;
                    hashCol[y][i] = false;
                    hashBlock[x/3][y/3][i] = false;
                }
            }
            board[x][y] = '.';
        }else{
            if(dfs(board, x, y+1)) return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        memset(hashRow, false, sizeof(hashRow));
        memset(hashCol, false, sizeof(hashCol));
        memset(hashBlock, false, sizeof(hashBlock));
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int d = board[i][j] - '0';
                    hashRow[i][d] = true;
                    hashCol[j][d] = true;
                    hashBlock[i/3][j/3][d] = true;
                }
            }    
        }
        dfs(board, 0, 0);	
    	return;
    }
};

char chessboard[][10]={
    "..9748...",
    "7........",
    ".2.1.9...",
    "..7...24.",
    ".64.1.59.",
    ".98...3..",
    "...8.3.2.",
    "........6",
    "...2759.."
};

int main(){
    vector<vector<char> > board;
    for(int i = 0; i < 9; ++i){
        vector<char> line;
        for(int j = 0; j < 9; ++j)
            line.push_back(chessboard[i][j]);
        board.push_back(line);
    }
    Solution sol;
    sol.solveSudoku(board);
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j)
            cout << board[i][j];
        cout << endl;
    }
}
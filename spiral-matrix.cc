#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >&matrix) {
        int m = 2, n = 2;
        m = matrix.size();
        if(m)n = matrix[0].size();
        vector<int>ans(m*n, 0);
        vector<bool>isVisited(m*n, false);
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for(int r = 0, c = 0, i = 0, d = 0; i < m * n; ++i){
        	ans[i] = matrix[r][c];
            isVisited[r*n+c] = true;
        	int rr = r + dx[d], cc = c + dy[d];
        	if(rr >= 0 && rr < m && cc >= 0 && cc < n && isVisited[rr*n+cc] == false){
        		r = rr, c = cc;
        	}else{
        		d = (d+1) % 4;	
        		r = r + dx[d], c = c + dy[d];
        	}
        }
    	return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int> >matrix;
    matrix.resize(2);
    matrix[0].push_back(1);
    matrix[0].push_back(2);
    matrix[1].push_back(3);
    matrix[1].push_back(4);
    auto ans = sol.spiralOrder(matrix);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
}
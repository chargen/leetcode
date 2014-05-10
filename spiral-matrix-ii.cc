#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > ans;
    	ans.resize(n);
    	for(int i = 0; i < n; ++i) ans[i].resize(n);
    	int dx[] = {0, 1, 0, -1};
    	int dy[] = {1, 0, -1, 0};
    	for(int r = 0, c = 0, i = 1, d = 0;
    		i <= n * n;
    		++i){
    		ans[r][c] = i;
    		int rr = r + dx[d], cc = c + dy[d];
    		if(rr >= 0 && rr < n && cc >= 0 && cc < n && ans[rr][cc] == 0){
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
	int n = 3;
	vector<vector<int> > ans = sol.generateMatrix(n);
	for(int i = 0; i < n; ++i){
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
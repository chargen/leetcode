#include <vector>
#include <algorithm>
using std::vector;
using std::min;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int nRows = triangle.size();
    	vector<int> cur = triangle[nRows-1];
    	for(int i = nRows-2; i >= 0; --i){
    		int nCols = triangle[i].size();
    		for(int j = 0; j < nCols; ++j)
    			cur[j] = min(cur[j], cur[j+1]);
    		for(int j = 0; j < nCols; ++j){
    			cur[j] += triangle[i][j];
    		}
    	}
    	return cur[0];
    }
};

int main(){

}
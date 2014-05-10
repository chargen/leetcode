#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> colIndex;
	int ans;
	void tryNth(int n, int k){
		if(n == k){
			++ans;
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

    int totalNQueens(int n) {
    	colIndex.resize(n);
		ans = 0;
    	tryNth(n, 0);
    	return ans;
    }
};

int main(){
	Solution sol;
	auto ans = sol.totalNQueens(8);
	cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
    	int f = 0, r = 1;
    	if(n == 1) return 0;
    	for(int i = 1; ; ++i){
    		//cout << "(" << f << "," << r << ")" << endl;
    		int rmost = 0;
    		for(int j = f; j < r; ++j)
    			rmost = max(rmost, j + A[j]);
    		if(rmost >= n-1) return i;
    		if(rmost + 1 <= r) break;
    		f = r, r = rmost + 1;
    	}
    	return -1;
    }
};

int main(){
	Solution sol;
	int A[] = {2, 3, 1, 1, 4};
	cout << sol.jump(A, 5) << endl;
	int B[] = {1, 2, 3};
	cout << sol.jump(B, 3) << endl;
}
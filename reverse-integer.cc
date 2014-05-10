#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	int sign = (x < 0) ? -1 : 1;
    	if(x == 0) return x;
    	long long X = x;
    	X = abs(X);
    	int ans = 0;
    	while(X){
    		int d = X % 10;
    		ans = ans * 10 + d;
    		X = X / 10;
    	}
    	return ans * sign;
    }
};

int main(){
	Solution sol;
	cout << sol.reverse(-123) << endl;
	cout << sol.reverse(0) << endl;
	cout << sol.reverse(1<<31) << endl;
}
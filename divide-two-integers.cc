#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int divide(int dividend_, int divisor_) {
    	vector<unsigned int> multiple;
    	unsigned int dividend = abs((long long)dividend_);
    	unsigned int divisor = abs((long long)divisor_);
    	int sign = 1;
    	if(dividend_ < 0) sign *= -1;
    	if(divisor_ < 0) sign *= -1;
    	if(divisor == 1) return dividend * sign;
    	for(unsigned int i = divisor; i <= dividend ; i <<=1 ){
    		multiple.push_back(i);
    		if(dividend - i < i) break;
    	}
    	int quo = 0;
    	for(int i = multiple.size() - 1; i >= 0; --i){
    		quo <<= 1;
    		if(dividend >= multiple[i]){
    			quo |= 1;
    			dividend -= multiple[i];
    		}
    	}
    	return quo * sign;
    }
};

int main(){
	Solution sol;
	cout << sol.divide(-2147483648, 2) << endl;
}
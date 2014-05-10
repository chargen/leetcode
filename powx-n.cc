class Solution {
public:
    double pow(double x, int n) {
    	bool isNeg = (n < 0);
    	long long k = n;
    	k = abs(k);
    	double ans = 1.0;
    	while(k){
    		if(k&1) ans *= x;
    		x *= x;
    		k >>= 1;
    	}
    	if(isNeg) ans = 1.0/ans;
    	return ans;
    }
};
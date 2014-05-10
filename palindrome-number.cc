class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0) return false;
    	long long rx = 0;
    	for(int i = x; i > 0; i/=10)
    		rx = rx * 10 + (i % 10);
    	return rx == x;
    }
};
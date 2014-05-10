class Solution {
public:
    int singleNumber(int A[], int n) {
    	int sum = 0, carry = 0;
    	for(int i = 0; i < n; ++i){
    		int a = (((sum^A[i])&(~carry))|(sum&A[i]&carry));
    		int b = ((sum&A[i]&(~carry))|((~sum)&(~A[i])&carry));
    		sum = a, carry = b;
    	}
    	return (sum|carry);
    }
};
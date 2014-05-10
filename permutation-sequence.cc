#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	int fact[10];
    	fact[0] = 1;
    	for(int i = 1; i < 10; ++i)
    		fact[i] = fact[i-1] * i;
    	int a[10];
    	--k;
    	for(int i = 0, j = n-1; i<n; ++i, --j){
    		a[i] = k / fact[j];
    		k %= fact[j];
    	}
    	int hash[10] = {0};
    	string ans = "";
    	for(int i = 0; i < n; ++i){
    		int v = a[i];
    		for(int j = 0; j < n; ++j){
    			if(hash[j] == 0){
    				if(v == 0){
    					hash[j] = 1;
    					ans += j + '1';
    					break;
    				}
    				--v;
    			}
    		}
    	}
    	return ans;
    }
};

int main(){
	Solution sol;
	cout << sol.getPermutation(4, 4) << endl;
	cout << sol.getPermutation(3, 6) << endl;
}
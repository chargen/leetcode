#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
    	if( x == 0 || x == 1) return x;
        int l = 0, r = x;
        while(l+1 < r){
        	int mid = (l+r)/2;
        	long long mid2 = mid;
        	mid2 *= mid;
        	if(mid2 > x) r = mid;
        	else l = mid;
        }
        return l;
    }
};

int main(){
	Solution sol;
	cout << sol.sqrt(2147483647) << endl;
	cout << sol.sqrt(121) << endl;
}
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	int len = s.length();
    	string ans = "";
    	int mid = (nRows-1)/2;
    	if(nRows == 1) return s;
    	int cycle = nRows + nRows - 2;
    	for(int j = 0; j < len; j += cycle)
    		ans += s[j];
    	for(int i = 1; i < nRows - 1; ++i){
    		for(int j = i, k = cycle - i;
    			j < len;
    			j += cycle, k += cycle){
    			ans += s[j];
    			if(k<len) ans+=s[k];
    		}
    	}
    	for(int j = nRows - 1; j < len; j += cycle)
    		ans += s[j];
    	return ans;
    }
};

int main(){
	Solution sol;
	cout << sol.convert("PAYPALISHIRING", 3) << endl;
}
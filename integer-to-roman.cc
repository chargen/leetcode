#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	int units[] = {1000, 500, 100, 50, 10, 5, 1};
    	char chars[] = "MDCLXVI";
    	string ans = "";
    	for(int i = 0; i < 7; i += 2){
    	   	if(num < units[i]) continue;
    	   	int d = num / units[i];
    		if(d <= 3){
    			for(int j = 0; j < d; ++j)
	    			ans += chars[i];
    		}else if(d == 4){
    			ans += chars[i];
    			ans += chars[i-1];
    		}else if(d >=5 && d<= 8){
    			ans += chars[i-1];
    			for(int j = 5; j < d; ++j)
	    			ans += chars[i];
    		}else if(d == 9){
    			ans += chars[i];
    			ans += chars[i-2];
    		}
    		num = num % units[i];
    	}
    	return ans;
    }
};

int main(){
	Solution sol;
	cout << sol.intToRoman(99) << endl;
	cout << sol.intToRoman(102) << endl;
}
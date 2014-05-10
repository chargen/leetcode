#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string countAndSay(string s){
	   	ostringstream os;
	   	for(int i = 0, len = s.length(), pre = 0; i < len; ++i){
    		if(i == len - 1 || s[i] != s[i+1]){
    			os << i - pre + 1 << s[i];
    			pre = i + 1;
    		}
    	}
    	return os.str();		
	}
    string countAndSay(int n) {
    	string str = "1";
    	for(int i = 1; i < n; ++i)
    		str = countAndSay(str);
    	return str;
    }
};

int main(){
	Solution sol;
	cout << sol.countAndSay(1) << endl;
	cout << sol.countAndSay(2) << endl;
	cout << sol.countAndSay(3) << endl;
	cout << sol.countAndSay(4) << endl;
}
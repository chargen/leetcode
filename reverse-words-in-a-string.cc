#include <string>
#include <iostream>
#include <sstream>
using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        string result = "";
        istringstream is(s);
        string str;
        bool first = true;
        while(is >> str){
        	if(!first) result = " " + result;
        	result = str + result;
        	first = false;
        }
        s = result;
    }
};

int main(){
	Solution sol;
	string str = "the sky is blue";
	sol.reverseWords(str);
	cout << str << endl;
}
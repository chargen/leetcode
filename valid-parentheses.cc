#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<char> st;
    	for(int i = 0; i < s.length(); ++i){
    		char c = s[i];
    		if(c == '(' || c == '{' || c == '[')
    			st.push(c);
    		else{
    			if(st.size() == 0) return false;
    			char top = st.top();
    			st.pop();
    			string tmp = "";
    			tmp += top;
    			tmp += c; 
    			if(tmp == "()" || tmp == "[]" || tmp == "{}")
    				continue;
    			else
    				return false;
    		}
    	}
    	return st.size() == 0;
    }
};

int main(){
	Solution sol;
	cout << sol.isValid("()") << endl;
}
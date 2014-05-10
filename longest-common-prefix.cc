#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int nStr = strs.size();
        string ans = "";
        if(nStr>1)for(int i=0, finish = 0; !finish; ++i){
        	for(int j = 0; j < nStr; ++j){
        		if(i >= strs[j].length() || strs[j][i] != strs[0][i]){
        			finish = 1;
        			break;
        		}
        	}
        	if(!finish) ans+=strs[0][i];
        }else if(nStr == 1)
        	ans = strs[0];
        return ans;
    }
};

int main(){}
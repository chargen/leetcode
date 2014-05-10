#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	vector<string> tmp;
	vector<string> ans;
	void restore(const string& s, int pos){
		if(tmp.size() == 4 && pos == s.length()){
			ans.push_back(tmp[0] + "." + tmp[1] + "." + tmp[2] + "." + tmp[3]);
			return;
		}
		if(tmp.size() == 4) return;
		string part = "";
		for(int i = pos; i < s.length(); ++i){
			part += s[i];
			if(part[0] == '0' && part.length() > 1) break;
			if(part.length() < 4 && (part.length() < 3 || part < "256")){
				tmp.push_back(part);
				restore(s, i+1);
				tmp.pop_back();
			}else
				break;
		}
	}
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        restore(s, 0);
        return ans;
    }
};

int main(){
	Solution sol;
	vector<string> ans = sol.restoreIpAddresses("25525511135");
	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
	ans = sol.restoreIpAddresses("010010");
	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
}
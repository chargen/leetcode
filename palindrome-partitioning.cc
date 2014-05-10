#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string> > ans;
	vector<int> tmp;
	void findAllPart(const string& s, int k, vector<vector<int> >& partPos){
		for(int i = 0; i < partPos[k].size(); ++i){
			tmp.push_back(partPos[k][i]);
			if(partPos[k][i] == 0){
				vector<string> ss;
				for(int i = tmp.size()-1; i >0; --i)
					ss.push_back(s.substr(tmp[i], tmp[i-1] - tmp[i]));
				//for(int i = 0; i < ss.size(); ++i)
				//	cout << ss[i] << " ";
				//cout << endl;
				ans.push_back(ss);
			}else
				findAllPart(s, partPos[k][i]-1, partPos);
			tmp.pop_back();
		}
	}
    vector<vector<string> > partition(string s) {
    	int len = s.length();
    	vector<bool> dp(len*len, false);
    	#define dp(x, y) dp[(x)*len+y]
    	for(int i = 0; i < len; ++i){
    		dp(i, i) = true;
    		if(i+1<len && s[i] == s[i+1]) dp(i, i+1) = true;
    	}
    	for(int d = 3; d <= len; ++ d){
	    	for(int i = 0; i + d <= len; ++i){
    			int l = i, r = i + d - 1;
    			if(s[l] == s[r] && dp(l+1, r-1) == true){
    				dp(l, r) = true;
    				//cout << s.substr(l, d) << endl;
    			}
    		}
    	}
    	vector<vector<int> > partPos(len);
    	for(int i = 0; i < len; ++i){
    		if(dp(0, i))
    			partPos[i].push_back(0);
    		for(int j = 0; j < i; ++j){
    			if(dp(j+1,i))
    				partPos[i].push_back(j+1);
    		}
    	}
    	ans.clear(), tmp.clear();
    	tmp.push_back(len);
    	findAllPart(s, len-1, partPos);
    	return ans;
    }
};

int main(){
	Solution sol;
	string s = "cbbbcc";
	sol.partition(s);
}
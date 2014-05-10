#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	int n = L.size();
    	vector<int> ans, counter;
    	map<string, int> hash;
    	if(n>0){
	    	int len = L[0].length();
	    	for(int i = 0; i < L.size(); ++i){
	    		if(hash.find(L[i]) == hash.end()){
	    			int t = hash.size();
	    			hash[L[i]] = t;
	    			counter.push_back(1);
	    		}else
	    			++counter[hash[L[i]]];
	    	}
	    	for(int start = 0; start < len; ++start){
	    		vector<int> tmp, count(counter);
	    		for(int i = start; i + len <= S.length(); i += len){
	    			string s = S.substr(i, len);
	    			if(hash.find(s) != hash.end())
	    				tmp.push_back(hash[s]);
	    			else tmp.push_back(-1);
	    		}
	    		if(tmp.size() < n) continue;
	    		for(int i = 0, cnt = 0; i < tmp.size(); ++i){
	    			if(i >= n && tmp[i-n] != -1){
	    				int t = tmp[i-n];
    					if(count[t] == 0) --cnt;
    					++count[t];
	    				if(count[t] == 0) ++cnt;
	    			}
	    			if(tmp[i] != -1){
		    			int t = tmp[i];
	    				if(count[t] == 0) --cnt;
	    				--count[t];
	    				if(count[t] == 0) ++cnt;
			    		if(cnt == hash.size())
			    			ans.push_back(start + (i - n + 1)*len);
	    			}
	    		}
	    	}
	   	}
	   	return ans;
    }
};

int main(){
	string S = "aaaaaaaaaaaaaaaaaa";
	vector<string> L ;
	L.push_back(string("a"));
	L.push_back(string("a"));
	L.push_back(string("a"));
	Solution sol;
	auto ans = sol.findSubstring(S, L);
   	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, ","));
	return 0;
}
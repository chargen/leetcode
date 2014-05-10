#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	map<string,vector<string>> hash;
    	vector<string> ans;
    	int n = strs.size();
    	for(int i = 0; i < n; ++i){
    		string key = strs[i];
    		sort(key.begin(), key.end());
    		hash[key].push_back(strs[i]);
    	}
    	for(auto p = hash.begin(); p != hash.end(); ++p){
    		if(p->second.size() >= 2 ){
    			for(int i = 0; i < p->second.size(); ++i)
    				ans.push_back(p->second[i]);
    		}
    	}
    	return ans;
    }
};

int main(){

}
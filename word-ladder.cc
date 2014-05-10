#include <queue>
#include <string>
#include <unordered_set>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		vector<string> level[2];
    	int ans = 0;
    	level[0].push_back(start);
    	for(int dist = 1; ; ++dist){
    		int cur = (dist&1);
    		int pre = cur ^ 1;
    		level[cur].clear();
    		for(int i = 0; i < level[pre].size(); ++i){
    			string top = level[pre][i];
    			for(int i = 0; i < top.size(); ++i){
    				string tmp = top;
	    			for(char c = 'a'; c <= 'z'; ++c){
	    				if(c == top[i]) continue;
	    				tmp[i] = c;
	    				if(tmp == end) return dist+1;
	    				if(dict.find(tmp) != dict.end()){
	    					//cout << top << " " << tmp << endl;
	    					level[cur].push_back(tmp);
	    					dict.erase(tmp);
	    				}
	    			}
	    		}
    		}
    		if(level[cur].size() == 0) break;
    	}
    	return 0;
    }
};

int main(){
	string start = "a";
	string end = "c";
    string strs[] = {"a","b","c"};
	unordered_set<string> dict;
	for(int i = 0; i < 3; ++i)
		dict.insert(strs[i]);
	Solution sol;
	cout << sol.ladderLength(start, end, dict) << endl;
}
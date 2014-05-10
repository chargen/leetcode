#include <string>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

const static string keys[10] = {
	string(" "),	//0
	string(""),		//1
	string("abc"),	//2
	string("def"),	//3
	string("ghi"),	//4
	string("jkl"),	//5
	string("mno"),	//6
	string("pqrs"),	//7
	string("tuv"),	//8
	string("wxyz")	//9
};
class Solution {
public:


	vector<string> ans;
	string tmp;
	void dfs(const string& digits, int k){
		if(k < 0){
			ans.push_back(tmp);
			return;
		}
		int d = digits[k] - '0';
		string t = tmp;
		for(int i = 0; i < keys[d].size(); ++i){
			char c = keys[d][i];
			tmp = c + t;
			dfs(digits, k - 1);
		}
		t.swap(tmp);
	}
    vector<string> letterCombinations(string digits) {
    	tmp = "";
    	ans.clear();
    	dfs(digits, digits.size() - 1);
    	return ans;
    }
};

int main(){
	Solution sol;
	auto ans = sol.letterCombinations("2");
	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " "));
}
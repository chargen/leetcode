#include <string>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    	int nWords =  words.size();
    	vector<string> ans;
    	for(int i = 0; i < nWords;){
    		int j = i+1, cnt = words[i].length();
    		while(j < nWords && cnt + words[j].length() + 1 <= L)
    			cnt += words[j++].length() + 1;
    		string tmp;
    		if(j == nWords){
    			tmp = words[i];
    			for(int k = i+1; k < j; ++k)
    				tmp += " " + words[k];
    			for(int i = cnt; i < L; ++i)
    				tmp += ' ';
    		}else if(j == i+1){
    			tmp = words[i];
    			for(int i = 0; i < L - cnt; ++i)
    				tmp += ' ';
    		}else{
    			int spaces = L - cnt;
    			int ave = spaces / (j - i - 1);
    			int rem = spaces % (j - i - 1);
    			tmp = words[i];
    			for(int k = i+1; k < j; ++k){
    				for(int p = 0; p <= ave; ++p)
    					tmp += ' ';
    				if(k-i <= rem)
    					tmp += ' ';
    				tmp += words[k];
    			}
    		}
    		ans.push_back(tmp);
    		i = j;
    	}
    	return ans;   
    }
};

int main(){
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	Solution sol;
	auto ans = sol.fullJustify(words, 16);
	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "<---\n"));
}
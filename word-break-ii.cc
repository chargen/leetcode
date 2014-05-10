#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string s;
    vector<vector<int> > sol;

    void findAns(int k , int len, string& tmp){
        if(k == len){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < sol[k].size(); ++i){
            int j = sol[k][i];
            string temp = tmp;
            if(k) temp += " ";
            temp += s.substr(k, j-k);
            findAns(j, len, temp);
        }
    }

    vector<string> wordBreak(string s_, unordered_set<string> &dict) {
        s = s_;
        int len = s.length();
        vector<bool> dp(len+1, false);
        sol.clear();
        sol.resize(len+1);
        dp[len] = true;
        for(int i = len-1; i >= 0; --i){
            for(int j = i+1; j <= len; ++j){
                if(dp[j]){
                    string t = s.substr(i, j-i);
                    if(dict.find(t) != dict.end()){
                        sol[i].push_back(j);
                        dp[i] = true;
                    }
                }
            }
        }
        ans.clear();
        string tmp = "";
        if(dp[0]) findAns(0, len, tmp);
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "catsanddog";
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    sol.wordBreak(s, dict);
}
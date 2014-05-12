#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> hash;
        for(int i = 0; i < T.length(); ++i) ++hash[T[i]];
        vector<int> pos;
        for(int i = 0; i < S.length(); ++i)
            if(hash.find(S[i]) != hash.end())
                pos.push_back(i);
        if(pos.size() == 0) return "";
        int bestL = -1, best = -1, n = pos.size();
        int f = 0, r = 0, nChar = hash.size();
        #define S(x) S[pos[x]]
        while(f < n){
            while(r < n && nChar){
                --hash[S(r)];
                if(hash[S(r)] == 0) --nChar;
                ++r;
            }
            if(nChar != 0) break;
            while(f < r && nChar == 0){
                if(best == -1 || pos[r-1] - pos[f] + 1 < best)
                    best = pos[r-1] - pos[f] + 1, bestL = pos[f];
                if(hash[S(f)] == 0) ++nChar;
                ++hash[S(f)];
                ++f;
            }
        }
        if(bestL == -1) return "";
        return S.substr(bestL, best);
    }
};


int main(){
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("bba", "ab") << endl;
}
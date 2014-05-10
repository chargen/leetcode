#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> tmp;
    void dfs(int k, int len, vector<vector<int> >& ans, const vector<int>&S){
        if(k == len) ans.push_back(tmp);
        else{
            int n = 0;
            while(k+n < len && S[k+n] == S[k]) ++n;
            for(int i = 0; i <= n; ++i){
                dfs(k+n, len, ans, S);
                tmp.push_back(S[k]);
            }
            for(int i = 0; i <= n; ++i)
                tmp.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        int len = S.size();
        sort(S.begin(), S.end());
        dfs(0, len, ans, S);
        return ans;
    }
};

int main(){
    Solution sol;
    int array[] = {1,2,3};
    vector<int> S(array, array+3);
    vector<vector<int> > res = sol.subsetsWithDup(S);
    for(int i = 0; i < res.size(); ++i){
        printf("[");
        copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
        printf("]");
        cout << endl;
    }  
}
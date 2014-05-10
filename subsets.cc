class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        int len = S.size();
        sort(S.begin(), S.end());
        for(int s = 0; s < (1<<len); ++s){
        	vector<int> tmp;
        	for(int i = 0; i < len; ++i){
        		if((1<<i)&s) tmp.push_back(S[i]);
        	}
        	ans.push_back(tmp);
        }
        return ans;
    }
};
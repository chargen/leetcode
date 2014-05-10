#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<vector<int> > ans;
    	sort(num.begin(), num.end());
    	int n = num.size();
    	while(true){
    		int pos = -1;
    		//copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
    		//cout << endl;
    		ans.push_back(num);
    		for(int i = n-2; i >= 0; --i){
    			if(num[i] < num[i+1]){
    				pos = i;
    				break;
    			}
    		}
    		//cout << pos << endl;
    		if(pos == -1) break;
    		int minpos = pos+1;
    		for(int i = pos+1; i < n; ++i){
    			if(num[i] > num[pos] && num[i] < num[minpos])
    				minpos = i;
    		}
    		swap(num[pos], num[minpos]);
    		sort(num.begin()+pos+1, num.end());
    	}
    	return ans;
    }
};

int main(){
	Solution sol;
	int array[] = {1,1,2};
	vector<int> num(array, array+3);
	sol.permuteUnique(num);
}
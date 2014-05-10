#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
    	vector<int> status(T.size(), 0);
    	for(int i = 0; i < S.size(); ++i){
    		for(int j = T.size() - 1; j > 0 ; --j)
    			if(S[i] == T[j]) 
    				status[j] += status[j-1];
    		if(S[i] == T[0]) status[0] += 1;
    	}
    	return status[T.size() - 1];
    }
};

int main(){
	Solution sol;
	cout << sol.numDistinct("aabb", "ab") << endl;
}
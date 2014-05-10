#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    	for(int i = 0; i < n;){
    		if(A[i] != i+1 && A[i]>=1 && A[i] <=n && A[A[i]-1] != A[i]){
    			swap(A[A[i]-1], A[i]);
    		}else
    			++i;
    	}
    	for(int i = 0; i < n; ++i)
    		if(A[i] != i + 1)
    			return i + 1;
    	return n + 1;
    }
};

int main(){
	Solution sol;
	int array[] = {3,4,-1,1};
	cout << sol.firstMissingPositive(array, 4) << endl;
}
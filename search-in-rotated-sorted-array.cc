#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
    	int l = 0, r = n;
    	while(l + 1 < r){
    		int mid = (l+r)/2;
    		if(A[mid] >= A[l]) l = mid;
    		else r = mid;
    	}
    	int sep = l;
    	//cout << "sep = " << sep << endl;
    	if(target == A[sep]) return sep;
    	if(target >= A[0] && target < A[sep]){
    		int l = 0 , r = sep;
   			while(l + 1 < r){
   				int mid = (l+r)/2;
   				if(A[mid] <= target) l = mid;
   				else r = mid;
   			}
   			if(A[l] == target) return l;
   		}
    	if(sep+1<n && target >= A[sep+1]){
    		int l = sep+1 , r = n;
   			while(l + 1 < r){
   				int mid = (l+r)/2;
   				if(A[mid] <= target) l = mid;
   				else r = mid;
   			}
   			if(A[l] == target) return l;
   		}
   		return -1;
    }
};

int main(){
	Solution sol;
	int A[] = {1,0};
	cout << sol.search(A, 1, 0) << endl;
	int B[] = {4,5,6,7,0,1,2};
	cout << sol.search(B, 7, 7) << endl;
	int C[] = {1,3,5};
	cout << sol.search(C, 3, 1) << endl;
}
#include <iostream>
using namespace std;

class Solution {
public:
    double findKthSortedArrays(int* A, int n, int* B, int m, int k) {
    	if(n == 0) return B[k];
    	if(m == 0) return A[k];
    	if(k == 0) return min(A[0], B[0]);
    	int p = (k+1) / 2, q = (k+1) - p;
    	if(p > n) p = n, q = (k+1) - p;
    	if(q > m) q = m, p = (k+1) - q;
    	int posa = p - 1, posb = q - 1;
    	int a = A[posa], b = B[posb];
    	if(a <= b) return findKthSortedArrays(A + p, n - p, B, m, k - p);
    	else return findKthSortedArrays(A, n, B + q, m - q, k - q);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if((m + n) % 2 == 0)
    		return (findKthSortedArrays(A, m, B, n, (m+n)/2) +
    			    findKthSortedArrays(A, m, B, n, (m+n)/2 - 1)) / 2.0;
    	else return findKthSortedArrays(A, m, B, n, (m+n)/2);
    }
};

int main(){
	Solution sol;
	int A[] = {2, 3, 4, 100000};
	int B[] = {1};
	cout << sol.findMedianSortedArrays(A, 3, B, 1) <<endl;
}
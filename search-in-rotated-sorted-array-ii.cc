#include <iostream>
using namespace std;

class Solution {
public:
  bool search(int A[], int n, int target) {
      int sep = n - 1;
      for(int i = 0; i+1<n; ++i){
        if(A[i] > A[i+1]){
          sep = i;
          break;
        }
      }
      //cout << "sep = " << sep << endl;
      if(target == A[sep]) return true;
      if(target >= A[0] && target < A[sep]){
        int l = 0 , r = sep;
        while(l + 1 < r){
          int mid = (l+r)/2;
          if(A[mid] <= target) l = mid;
          else r = mid;
        }
        if(A[l] == target) return true;
      }
      if(sep+1<n && target >= A[sep+1]){
        int l = sep+1 , r = n;
        while(l + 1 < r){
          int mid = (l+r)/2;
          if(A[mid] <= target) l = mid;
          else r = mid;
        }
        if(A[l] == target) return true;
      }
      return false;
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
  int D[] = {1,3,1,1};
  cout << sol.search(D, 4, 3) << endl;
  int E[] = {1,1,1,3,1};
  cout << sol.search(E, 5, 3) << endl;
}
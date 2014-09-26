#include <iostream>
#include <algorithm>
using std::max;
using std::cout;
using std::endl;
class Solution {
public:
    int maxProduct(int A[], int n) {
        long long posMin = 1, negMax = 1, multiple = 1, ans = A[0];
        for(int i = 0; i < n; ++i){
            multiple *= A[i];
            ans = max(ans, multiple/posMin);
            if(negMax < 0) ans = max(ans, multiple/negMax);
            if(multiple == 0){
                posMin = 1, negMax = 1, multiple = 1;
                continue;
            }
            if(multiple > 0 && multiple < posMin) posMin = multiple;
            if(multiple < 0 && (multiple > negMax || negMax > 0)) negMax = multiple;
        }
        return ans;
    }
};

int main(){
    //int A[] = {2,3,-2,4};
    //int A[] = {2,3,-2,4};
    //int A[] = {2,3,-2,4};
    int A[] = {1, 1, 1, 1, 1, 2, 2, 3, 4};
    Solution sol;
    cout << sol.maxProduct(A, sizeof(A)/sizeof(A[0])) << endl;
}
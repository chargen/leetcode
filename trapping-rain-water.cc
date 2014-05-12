class Solution {
public:
    int trap(int A[], int n) {
        int ans = 0;
        vector<int> R(n+1, 0);
        for(int i = n-1; i >= 0; --i)
            if(i == n-1 || A[i] > R[i+1])
                R[i] = A[i];
            else
                R[i] = R[i+1];
        for(int i = 0, L = 0; i < n; ++i){
            int H = min(L, R[i+1]);
            if(H > A[i]) ans += H - A[i];
            L = max(L, A[i]);
        }
        return ans;
    }
};

class Solution {
public:
    static const int INF = 0x3f3f3f3f;
    int largestRectangleArea(vector<int> &height) {
        int n = height.size(), ans = 0;
        if(n == 0) return ans;
        vector<int> L(n, 0), R(n, 0);
        L[0] = 0;
        for(int i = 1; i < n; ++i){
            int j = i - 1;
            while(j >= 0){
                if(height[i] > height[j]){
                    L[i] = j + 1;
                    break;
                }
                j = L[j] - 1;
            }
            if(j < 0) L[i] = 0;
        }
        R[n-1] = n - 1;
        for(int i = n - 2; i >= 0; --i){
            int j = i + 1;
            while(j < n){
                if(height[i] > height[j]){
                    R[i] = j - 1;
                    break;
                }
                j = R[j] + 1;
            }
            if(j == n) R[i] = n - 1;
        }
        for(int i = 0; i < n; ++i) ans = max(ans, height[i] *(R[i] - L[i] + 1));
        return ans;
    }
};
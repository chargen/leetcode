class Solution {
public:
    int candy(vector<int> &ratings) {
    	int n = ratings.size();
        vector<int> poles, given(n, 1);
        int ans = 0, pre = -1;
        for(int i = 0; i < n; ++i){
        	if( (i == 0||ratings[i] >= ratings[i-1]) && (i == n-1||ratings[i] >= ratings[i+1])
        	  ||(i == 0||ratings[i] <= ratings[i-1]) && (i == n-1||ratings[i] <= ratings[i+1])){
        		if(pre != -1){
		        	if(ratings[pre] > ratings[i]){
		        		for(int j = i, v = 1; j >= pre; --j, ++v)
		        			given[j] = max(v, given[j]);        		
		        	}else if(ratings[pre] < ratings[i]){
		        		for(int j = pre, v = 1; j <= i; ++j, ++v)
		        			given[j] = max(v, given[j]);
		        	}else for(int j = pre+1; j < i; ++j)
		        			given[j] = max(1, given[j]);
        		}
        		pre = i;
        	}
        }
        for(int i = 0; i < n; ++i) ans += given[i];
        return ans;
    }
};
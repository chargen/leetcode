class Solution {
public:
    int atoi(const char *str) {
    	int sign = 1;
    	int len = strlen(str);
    	int start = 0;
    	for(int i = 0; i < len; ++i){
    		if(str[i] == '+'){
    			sign = 1, start = i+1;
    			break;
    		}else if(str[i] == '-'){
    			sign = -1, start = i+1;
    			break;
    		}else if(str[i] >= '0' and str[i] <= '9'){
    			start = i;
    			break;
    		}else if(str[i] != ' ')
    			return 0;
    	}
    	long long ans = 0;
    	for(int i = start; i < len; ++i){
    		if(str[i] >= '0' and str[i] <= '9')
    			ans = ans * 10 + str[i] - '0';
    		else break;
    	}
    	ans *= sign;
    	if(ans > INT_MAX) ans = INT_MAX;
    	else if(ans < INT_MIN) ans = INT_MIN;
    	return ans;
    }
};
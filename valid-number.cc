#include <stdio.h>
#include <string.h>

class Solution {
public:
    bool isNumber(const char *s) {
    	const char* str = &s[0];
    	while(str[0]==' ')++str;
    	int len = strlen(str);
    	while(len > 0 && str[len-1]==' ') --len;
    	if(len == 0) return false;
    	int exp = -1, point = -1, digit = 0;
    	for(int i = 0; i < len; ++i){
    	   	if(str[i]>='0' && str[i] <='9'){
    	   		++digit;
    	   	}else if(str[i]=='e'){
    	   		if(digit == 0) return false;					// there must be some digit before 'e'
    	   		if(exp == -1) exp = i;
    	   		else return false;								// multiple 'e's are not allowed 
    	   	}else if(str[i]=='+' || str[i]=='-'){
    	   		if(i!=0 && str[i-1]!='e')return false;			// +/- must appear in the head or in the next position of 'e'
    	   	}else if(str[i]=='.'){
    	   		if(point == -1) point = i;
    	   		else return false;								// only one '.' is allowed
    	   	}else return false;									// invalid chars
    	}
    	if(digit == 0) return false;							// no digit
    	if(exp != -1){
    		if(str[exp+1] == '+' || str[exp+1] =='-') ++exp;
    		if(exp == len-1) return false;
    		for(int i = exp+1; i < len; ++i)
    			if(str[i] <'0' || str[i] >'9')return false;		// all chars behind 'e' should be digits			
    	}
        return true;
    }
};

int main(){
	Solution sol;
	printf("%s\n", sol.isNumber("0") ? "true" : "false");
	printf("%s\n", sol.isNumber(" 0.1 ") ? "true" : "false");
	printf("%s\n", sol.isNumber("abc") ? "true" : "false");
	printf("%s\n", sol.isNumber("1 a") ? "true" : "false");
	printf("%s\n", sol.isNumber("2e10") ? "true" : "false");
	printf("%s\n", sol.isNumber("078332e437") ? "true" : "false");
	printf("%s\n", sol.isNumber("e") ? "true" : "false");
	printf("%s\n", sol.isNumber(".") ? "true" : "false");
}
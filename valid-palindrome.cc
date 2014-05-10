class Solution {
public:
    bool isPalindrome(string s) {
    	string str = "";
    	for(int i = 0, len = s.length(); i < len; ++i){
    		if(s[i] >='a' && s[i] <='z' ||s[i] >='0' && s[i] <='9' )
    			str += s[i];
    		else if(s[i] >='A' && s[i] <='Z')
    			str += s[i] - 'A' +'a';
    	}
    	for(int i = 0, j = str.length() - 1; i < j; ++i, --j){
    		if(str[i] != str[j])
    			return false;
    	}
    	return true;
    }
};
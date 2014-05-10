class Solution {
public:
    int romanToInt(string s) {
    	int r2i[300];
    	r2i['I'] = 1;
    	r2i['V'] = 5;
    	r2i['X'] = 10;
    	r2i['L'] = 50;
    	r2i['C'] = 100;
    	r2i['D'] = 500;
    	r2i['M'] = 1000;
    	int result = 0;
    	for(int i = 0; i < s.length(); ++i){
    		if(i+1==s.length() || r2i[s[i]] >= r2i[s[i+1]])
    			result += r2i[s[i]];
    		else
    			result -= r2i[s[i]];
    	}
    	return result;
    }
};
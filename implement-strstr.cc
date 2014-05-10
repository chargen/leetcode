#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int lenNeedle = strlen(needle);
        int lenHaystack = strlen(haystack);
        vector<int> fail(lenNeedle, -1);
        for(int i = 1; i < lenNeedle; ++i){
        	int pos = fail[i - 1];
        	while(pos != -1 && needle[pos+1] != needle[i])
        		pos = fail[pos];
        	if(needle[pos+1] != needle[i]) fail[i] = -1;
        	else fail[i] = pos + 1;
        }
        for(int i = 0; i < lenNeedle; ++i)
        		cout << fail[i] << " ";
        cout << endl;
        int pos = 0, cur = -1;
        for(; pos < lenHaystack && cur < lenNeedle - 1; ++pos){
        	while(cur != -1 && haystack[pos] != needle[cur+1])
        		cur = fail[cur];
        	if(haystack[pos] != needle[cur+1]) cur = -1;
        	else cur = cur + 1;
        }
        cout << cur << " " << lenNeedle << endl;
        if(cur == lenNeedle - 1){
        	cout << haystack + pos - lenNeedle << endl;
        	return haystack + pos - lenNeedle;
        }
        return NULL;
    }
};

int main(){
	Solution sol;
	sol.strStr("ababaaa", "ababaaa");
	sol.strStr("mississippi", "issip");
}
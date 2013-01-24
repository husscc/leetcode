/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen=strlen(s);
        if(slen==0)
			return 0;
		
		int startpos=-1,endpos=0;
		for(int i=slen-1;i>=0;i--){
			if(s[i]!=' '){
				endpos=i+1;
				break;
			}
		}
		
		for(int i=0;i<endpos;i++){
			if(s[i]==' ')
				startpos=i;
		}
		return (endpos-1-startpos);
    }
};
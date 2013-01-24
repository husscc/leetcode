/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	const char *ptr_s=s,*ptr_p=p,*pstar,*s_tmp;
		bool star=false;
		
		while(*ptr_s!='\0'){
			if(*ptr_p=='?'||*ptr_s==*ptr_p){
				ptr_p++;
				ptr_s++;
			}
			
			else if(*ptr_p=='*'){
				star=true;
				do{
					ptr_p++;
				}
                while(*ptr_p=='*');
				
				if(*ptr_p=='\0')
					return true;
					
				pstar=ptr_p;            //record the location of '*'
                s_tmp=ptr_s;            //firstly match from none;
			}
			
			else{
				if(!star)
					return false;
				
				ptr_p=pstar;
                ptr_s=s_tmp;
                ptr_s++;
                s_tmp++;
			}		
		}
		
		while(*ptr_p=='*')
			ptr_p++;
		
		if(*ptr_p=='\0')
			return true;
		else
			return false;
    }
};
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
        int slen=strlen(s),plen=strlen(p);
        vector<vector<unsigned char> > f(slen+1,vector<unsigned char>(plen+1,0x0));
		
		f[0][0]=0x1;
		
        for(int i=0;i<slen;i++){
            if(s[i]!='*')
                break;
            f[i+1][0]=0x1;
        }
        for(int j=0;j<plen;j++){
            if(p[j]!='*')
                break;
            f[0][j+1]=0x1;
        }
		
		int k;
		for(int i=1;i<slen+1;i++){
			for(int j=1;j<plen+1;j++){
				//if(f[i][j])
				//	continue;
				if(!f[i-1][j]&&!f[i][j-1]&&!f[i-1][j-1])
					continue;
				if(s[i-1]=='*'&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1])){
					if(i==slen)
						return true;
					for(k=j;k<plen+1;k++)
						f[i][k]=0x1;
				}	
				
				if(p[j-1]=='*'&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1])){
					if(j==plen)
						return true;
					for(k=i;k<slen+1;k++)
						f[k][j]=0x1;
				}
				
				if(!f[i][j]&&f[i-1][j-1]&&(s[i-1]==p[j-1]||s[i-1]=='?'||p[j-1]=='?'))
					f[i][j]=0x1;
			}
		}
		
		return (bool)f[slen][plen];
    }
};
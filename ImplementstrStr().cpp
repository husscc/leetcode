/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

kmp?
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int stacklen=strlen(haystack),needlelen=strlen(needle);
        if(needlelen==0)
            return haystack;
    	else if(stacklen==0||stacklen<needlelen)
			return NULL;
		
		int *pattern=(int*)malloc(sizeof(int)*needlelen);
		memset(pattern,0,sizeof(int)*needlelen);
		
		for(int i=1,j=0;i<needlelen;i++){
			if(needle[j]==needle[i]){
				pattern[i]=pattern[i-1]+1;
				j++;
			}
			else
				j=0;
		}
		
		int s_ptr,n_ptr;
		for(s_ptr=0,n_ptr=0;s_ptr<stacklen&&n_ptr<needlelen;s_ptr++){
			if(haystack[s_ptr]==needle[n_ptr])
				n_ptr++;
			else if(n_ptr>0){
				n_ptr=pattern[n_ptr-1];
                s_ptr--;        //be careful this line
			}
		}
		
		if(s_ptr==stacklen&&n_ptr!=needlelen)
			return NULL;
		else{
			int len=needlelen+1+stacklen-s_ptr;
			char* res=(char*)malloc(sizeof(char)*len);
			memset(res,'\0',len);
			memcpy(res,needle,needlelen);
			if(s_ptr!=stacklen)
				memcpy(&res[needlelen],&haystack[s_ptr],(stacklen-s_ptr));
			return res;
		}
    }
};
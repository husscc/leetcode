/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {

    inline int to_int(char a,char b){
        if(a=='0')
            return 99;
        else
		    return 10*(a-'0')+(b-'0');
	}
	
	inline int to_int(char a){
		return a-'0';
	}

public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len=s.size();
		if(!len)
			return 0;
			
		int *res=(int*)malloc(len*sizeof(int));
		memset(res,0,len*sizeof(int));
		
		if(to_int(s[0]))
			res[0]=1;	
		if(len==1)
			return res[0];
		
		if(to_int(s[1]))
			res[1]+=res[0];
		if(26-to_int(s[0],s[1])>=0)
			res[1]++;
		
		for(int i=2;i<len;i++){
			if(to_int(s[i]))
				res[i]+=res[i-1];
			if(26-to_int(s[i-1],s[i])>=0)
				res[i]+=res[i-2];
		}
		
		return res[len-1];
    }
};
/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen=s.size();
		if(slen<2)
			return s;
		
		int max_len=1,max_pos=0;
		vector<unsigned char> odd(slen,true);
		vector<unsigned char> even(slen,true);
		
		bool flag=true;
		for(int i=3;i<=slen&&flag;i=i+2){
			flag=false;
			for(int j=0;j+i-1<slen;j++){
				if(odd[j+1]&&s[j]==s[j+i-1]){
					odd[j]=true;
					flag=true;
					max_len=i;
					max_pos=j;
				}
				else{
					odd[j]=false;
				}
			}
		}
		
		flag=true;
		for(int i=2;i<=slen&&flag;i=i+2){
			flag=false;
			for(int j=0;j+i-1<slen;j++){
				if(even[j+1]&&s[j]==s[j+i-1]){
					even[j]=true;
					flag=true;
					if(i>max_len){
						max_len=i;
						max_pos=j;
					}
				}
				else{
					even[j]=false;
				}
			}
		}
		
		s=s.substr(max_pos,max_len);
		return s;
    }
};
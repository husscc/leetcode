/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
class Solution {
	
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function     
		int slen=S.size(),tlen=T.size();
		
		if(!slen||!tlen||slen<tlen)
			return 0;
		
		vector<vector<int> >f (tlen,vector<int>(slen,0));	
		//initialize;
		for(int j=0;j<slen-tlen+1;j++){
			if(T[0]==S[j])
				f[0][j]=1;
		}

		for(int i=1;i<tlen;i++){
			for(int j=i;j<slen-tlen+(i+1);j++){
				if(T[i]==S[j]){
					for(int k=i-1;k<j;k++)
						f[i][j]+=f[i-1][k];
				}
			}
		}
		int res=0;
		for(int i=slen-1;i>tlen-2;i--)
			res+=f[tlen-1][i];
		
		return res;
    }
};
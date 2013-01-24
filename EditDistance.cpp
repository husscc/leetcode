/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
    inline int findmin(int a,int b,int c){
		a=a<b?a:b;
		c=c<a?c:a;
		return c;
	}
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1=word1.size(),len2=word2.size();
		vector<vector<int> > res(len1+1,vector<int>(len2+1,0));
		
		for(int i=0;i<len1+1;i++)
			res[i][0]=i;
		for(int i=0;i<len2+1;i++)
			res[0][i]=i;
		
		for(int i=1;i<len1+1;i++){
			for(int j=1;j<len2+1;j++){
				if(word1[i-1]==word2[j-1])
					res[i][j]=res[i-1][j-1];
				else
					res[i][j]=1+findmin(res[i-1][j],res[i][j-1],res[i-1][j-1]);
			}
		}
		
		return res[len1][len2];
    }
};
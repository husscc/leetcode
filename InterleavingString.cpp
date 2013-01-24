/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1=s1.size(),len2=s2.size(),len3=s3.size();
    	if((len1+len2)!=len3)
			return false;
		vector<vector<unsigned char> > res_matrix(len1+1,vector<unsigned char>(len2+1,0));
		
        res_matrix[0][0]=1;
        
		for(int i=1;i<len1+1;i++){
			if(s1[i-1]==s3[i-1])
				res_matrix[i][0]=1;
			else
				break;
		}
		
		for(int i=1;i<len2+1;i++){
			if(s2[i-1]==s3[i-1])
				res_matrix[0][i]=1;
			else 
				break;
		}
		
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				if(res_matrix[i][j+1]&&s1[i]==s3[i+j+1])
					res_matrix[i+1][j+1]=1;
				else if(res_matrix[i+1][j]&&s2[j]==s3[i+j+1])
					res_matrix[i+1][j+1]=1;
			}
		}
		
		return (bool)res_matrix[len1][len2];
    }
};		
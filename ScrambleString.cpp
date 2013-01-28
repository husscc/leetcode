/*
Given a string s1, we may represent it as a binary tree 
by partitioning it to TWO NON-EMPTY SUBSTRINGS RECURSIVELY.

Below is ONE POSSIBLE representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen=s1.size();
		if(slen!=s2.size())
			return false;
        vector<vector<vector<unsigned char> > > matrix;
		
		for(int i=0;i<slen;i++)
			matrix.push_back(vector<vector<unsigned char> >(slen-i,vector<unsigned char>(slen-i,0x0)));
			
		for(int i=0;i<slen;i++){
			for(int j=0;j<slen;j++){
				if(s1[i]==s2[j])
					matrix[0][i][j]=1;
			}
		}
		
		for(int i=1;i<slen;i++){
			for(int j=0;j<slen-i;j++){
				for(int k=0;k<slen-i;k++){
					for(int l=0;l<i;l++){
						if(
							(matrix[l][j][k]&&matrix[i-l-1][j+l+1][k+l+1])||
							(matrix[l][j][k+i-l]&&matrix[i-l-1][j+l+1][k])
						){
							matrix[i][j][k]=1;
							break;
						}
					}
				}
			}
		}
		return matrix[slen-1][0][0];
    }
};

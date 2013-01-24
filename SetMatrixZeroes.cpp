/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(!matrix.size())
			return;
			
        int R=-1,C=-1;
    	
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[0].size();j++){
                if(!matrix[i][j]){
				    if(R<0)
					    R=j;
				    matrix[i][R]=0;
				
				    if(C<0)
					    C=i;
				    matrix[C][j]=0;
                }
			}
		}
		if(R>-1){
			for(int i=0;i<matrix.size();i++){
				if(i!=C&&!matrix[i][R]){
					for(int j=0;j<matrix[0].size();j++)
						matrix[i][j]=0;
				}
			}
			for(int i=0;i<matrix[0].size();i++){
				if(!matrix[C][i]){
					for(int j=0;j<matrix.size();j++)
						matrix[j][i]=0;
				}
			}
			for(int i=0;i<matrix[0].size();i++)
				matrix[C][i]=0;
		}
		
		return;
    }
};
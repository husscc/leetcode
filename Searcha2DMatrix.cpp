/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row=matrix.size(),column;
    	if(!row||!(column=matrix[0].size()))
			return false;
		
		if(target<matrix[0][0]||target>matrix[row-1][column-1])
			return false;
			
		int start,end;
		if(target>=matrix[row-1][0])
			row=row-1;
		else{
			start=0;
			end=row-1;
			while(1){
				row=(start+end)/2;
				if(matrix[row][0]<=target&&target<matrix[row+1][0])
					break;
				else if(target<matrix[row][0])
					end=row-1;
				else
					start=row+1;
			}
		}
		
		start=0;end=column-1;
		while(start<=end){
			column=(start+end)/2;
			if(matrix[row][column]==target)
				return true;
			else if(target<matrix[row][column])
				end=column-1;
			else
				start=column+1;
		}
		
		return false;
		
    }
};
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()<2)
			return;
		int len=matrix.size();
		for(int i=0;i<len/2;i++){
			for(int j=0;j<len-1-2*i;j++){
				swap(matrix[i][i+j],matrix[i+j][len-1-i]);
				swap(matrix[i][i+j],matrix[len-1-i][len-1-i-j]);
				swap(matrix[i][i+j],matrix[len-1-i-j][i]);
			}
		}
    }
};

													1->(i,i+j)				0,0
swap(1,2)	swap(1,4)	swap(1,3)					2->(i+j,len-1-i)		0,1
	b  a		d  a       c  a						3->(len-1-i-j,i)		1,0
	c  d        c  b       d  b						4->(len-1-i,len-1-i-j)	1,1
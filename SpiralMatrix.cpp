/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if(!matrix.size())
			return res;
		
		int horizontal=matrix[0].size()-1,vertical=matrix.size()-1,x=0,y=0;
		
		while(horizontal>0&&vertical>0)
		{
			for(int i=0;i<horizontal;i++)
				res.push_back(matrix[x][y++]);
			for(int i=0;i<vertical;i++)
				res.push_back(matrix[x++][y]);
			for(int i=0;i<horizontal;i++)
				res.push_back(matrix[x][y--]);
			for(int i=0;i<vertical;i++)
				res.push_back(matrix[x--][y]);
				
			x++;
			y++;
			horizontal-=2;
			vertical-=2;
		}
		
		int total=matrix[0].size()*matrix.size();
		if(total>res.size()){
			for(int i=0;i<horizontal;i++)
				res.push_back(matrix[x][y++]);
			for(int i=0;i<vertical;i++)
				res.push_back(matrix[x++][y]);
            
			if(total>res.size())                    //please notice here : total-1==res.size()
				res.push_back(matrix[x][y]);
		}
		
		return res;
    }
};
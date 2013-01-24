/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 
(i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!triangle.size())
			return 0;

		int *last=new int[triangle.size()];
		int *cr=new int[triangle.size()];
		
		last[0]=triangle[0][0];

		for(int i=1;i<triangle.size();i++){
			cr[0]=last[0]+triangle[i][0];
			for(int j=1;j<triangle[i].size()-1;j++){
				cr[j]=triangle[i][j]+min(last[j-1],last[j]);
			}
			cr[triangle[i].size()-1]=last[triangle[i-1].size()-1]+triangle[i][triangle[i].size()-1];

			int *tmp=last;
			last=cr;
			cr=tmp;
		}

		int res=last[0];

		for(int i=1;i<triangle.size();i++)
			res=min(res,last[i]);

		return res;
    }
};

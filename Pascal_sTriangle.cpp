/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	vector<vector<int> > res;
        if(numRows<1)
			return res;
		
		res.push_back(vector<int>(1,1));	
		vector<int> currow;
		
		for(int i=1;i<numRows;i++){
			currow.clear();
			currow.push_back(1);
			for(int j=1;j<i;j++)
				currow.push_back(res[i-1][j-1]+res[i-1][j]);
			currow.push_back(1);
			res.push_back(currow);
		}
		return res;
    }
};
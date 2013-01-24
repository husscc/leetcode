/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(obstacleGrid.size()>0&&obstacleGrid[0].size()>0);
    	
		int m=obstacleGrid.size(),n=obstacleGrid[0].size();
		
		if(obstacleGrid[m-1][n-1]||obstacleGrid[0][0])
			return 0;
		
		int *line1=new int[n];
		int *line2=new int[n];
		
		line1[0]=1;
		for(int i=1;i<n;i++){
			if(obstacleGrid[0][i])
				line1[i]=0;
			else
				line1[i]=line1[i-1];
		}
		
		for(int i=1;i<m;i++){
            if(obstacleGrid[i][0])
                line2[0]=0;
            else
			    line2[0]=line1[0];
                
			for(int j=1;j<n;j++){
				if(obstacleGrid[i][j])
					line2[j]=0;
				else
					line2[j]=line2[j-1]+line1[j];
			}
            
			int *tmp=line1;
			line1=line2;
			line2=tmp;
		}
		
		return line1[n-1];
    }
};
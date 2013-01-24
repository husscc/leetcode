/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(m>0&&n>0);
    	
		int *line1=new int[n];
		int *line2=new int[n];
		
		for(int i=0;i<n;i++)
            line1[i]=1;
		
		for(int i=1;i<m;i++){
			line2[0]=1;
            
			for(int j=1;j<n;j++)
				line2[j]=line2[j-1]+line1[j];
			
			int *tmp=line1;
			line1=line2;
			line2=tmp;
		}
		
		return line1[n-1];
    }
};



/*
** recursive version: Time Limit Exceeded
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==1&&n==1)
    		return 1;
		else if(m==1)
			return uniquePaths(m,n-1);
		else if(n==1)
			return uniquePaths(m-1,n);
		else
			return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
*/
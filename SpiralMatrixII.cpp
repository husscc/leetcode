/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	n=abs(n);
		
		if(!n){
			vector<vector<int> > res;
			return res;
		}
		
		vector<vector<int> > res(n,vector<int>(n,0));
		
		int linelen=n-1;
		
		for(int i=1,x=0,y=0;linelen>0;){
		
			for(int j=0;j<linelen;j++,y++,i++)
				res[x][y]=i;
			for(int j=0;j<linelen;j++,x++,i++)
				res[x][y]=i;
			for(int j=0;j<linelen;j++,y--,i++)
				res[x][y]=i;
			for(int j=0;j<linelen;j++,x--,i++)
				res[x][y]=i;
			
			linelen-=2;
			x++;
			y++;
		}
		
		if(n&0x1)
			res[n/2][n/2]=n*n;
			
		return res;
		
    }
};
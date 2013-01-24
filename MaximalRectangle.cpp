/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int xsize=matrix.size();
        if(xsize==0)
			return 0;
		
		int ysize=matrix[0].size();
		if(ysize==0)
			return 0;
		
		for(int y=0;y<ysize;y++){		//calculate the "height" of each column
			if(matrix[0][y]=='1')
				matrix[0][y]=1;
			else
				matrix[0][y]=0;
				
			for(int x=1;x<xsize;x++){
				if(matrix[x][y]=='1')
					matrix[x][y]=matrix[x-1][y]+1;
				else
					matrix[x][y]=0;
			}
		}
		
		int maxr=0;
		int *height=new int[ysize];
		int *pos=new int[ysize];
		
		for(int x=0;x<xsize;x++){
			for(int y=0;y<ysize;y++){
				if(matrix[x][y]>0){
					int ptr=-1,area;
					for(;y<ysize&&matrix[x][y]>0;y++){
						if(ptr<0||matrix[x][y]>height[ptr]){
							height[++ptr]=matrix[x][y];
							pos[ptr]=y;
						}
						else if(matrix[x][y]<height[ptr]){
							while(ptr>=0&&matrix[x][y]<height[ptr]){
								area=height[ptr]*(y-pos[ptr]);
								maxr=max(maxr,area);
								ptr--;
							}
							height[++ptr]=matrix[x][y];
						}
					}
					while(ptr>=0){			//stack is not empty
						area=height[ptr]*(y-pos[ptr]);
						maxr=max(maxr,area);
						ptr--;
					}
				}
			}
		}
		delete []height;
		delete []pos;
		return maxr;
    }
};
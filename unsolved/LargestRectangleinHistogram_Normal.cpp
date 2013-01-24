/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

PS:determined by the lowest bar
PS2: Time Limit Exceeded
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size()<1)
            return 0;
        int area=0,tmp_area;
    	for(int i=0,j,k;i<height.size();i++){
			for(j=i-1;j>=0;j--){
				if(height[j]<height[i])
					break;
			}
			j++;
			for(k=i+1;k<height.size();k++){
				if(height[k]<height[i])
					break;
			}
			k--;
			tmp_area=height[i]*(k-j+1);
			area=area>tmp_area?area:tmp_area;
		}
		return area;
    }
};
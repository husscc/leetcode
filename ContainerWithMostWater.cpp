/*
Given n non-negative integers a1, a2, ..., an, 
where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int max=0,i=0,j=height.size()-1;
		if(j<1)
			return max;
		while(i<j){
			max=max>((j-i)*(height[i]<height[j]?height[i]:height[j]))?max:((j-i)*(height[i]<height[j]?height[i]:height[j]));
			if(height[i]<height[j])
				i++;
			else 
				j--;
		}
		return max;
	}
};
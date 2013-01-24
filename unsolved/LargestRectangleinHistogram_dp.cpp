/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

PS:determined by the lowest bar
PS2: Time Limit Exceeded
dp X
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size()<1)
            return 0;
        
        //vector<int> area(height.begin(),height.end());
		vector<int>	lowbar(height.begin(),height.end());
		int max_area=0,area,highest;
        for(int i=0;i<height.size();i++)
            max_area=max_area>height[i]?max_area:height[i];
        
		for(int barlen=2;barlen<=height.size();barlen++){
            lowbar[0]=lowbar[0]<lowbar[1]?lowbar[0]:lowbar[1];
			highest=lowbar[0];
			for(int i=1;i<=height.size()-barlen;i++){
				lowbar[i]=lowbar[i]<lowbar[i+1]?lowbar[i]:lowbar[i+1];
				highest=highest>lowbar[i]?highest:lowbar[i];
			}
			area=barlen*highest;
			max_area=max_area>area?max_area:area;
		}
		return max_area;
    }
};


0-0 1-1	2-2	3-3	4-4	......	n-1-n-1	n-n
0-1	1-2	2-3	3-4	4-5	......	n-1-n
0-2	1-3	2-4	3-5
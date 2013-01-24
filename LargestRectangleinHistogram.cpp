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
    struct PosInfo{
		int height;
		int pos;
		PosInfo(int h,int p):height(h),pos(p){}
	};
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size()<1)
            return 0;
        
    	stack<PosInfo> posinfo;
		int max_area=0,area,lastpos;
		for(int i=0;i<height.size();i++){
			if(posinfo.empty()||posinfo.top().height<height[i])
				posinfo.push(PosInfo(height[i],i));
			else if(posinfo.top().height>height[i]){
				while(!posinfo.empty()&&posinfo.top().height>height[i]){
					lastpos=posinfo.top().pos;				//be careful here
					area=posinfo.top().height*(i-lastpos);
					posinfo.pop();
					max_area=max_area>area?max_area:area;
				}
				posinfo.push(PosInfo(height[i],lastpos));
			}
		}
		while(!posinfo.empty()){
			area=posinfo.top().height*(height.size()-posinfo.top().pos);
			max_area=max_area>area?max_area:area;
			posinfo.pop();
		}
		return max_area;
    }
};

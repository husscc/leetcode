/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    struct comp{
		bool operator()(Interval a,Interval b){return a.start<b.start;}
	} compobj;
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(intervals.size()<2)
			return intervals;
		sort(intervals.begin(),intervals.end(),compobj);
		vector<Interval> res;
		
		int start=intervals[0].start,end=intervals[0].end;
		for(int i=1;i<intervals.size();i++){
			if(end<intervals[i].start){
				res.push_back(Interval(start,end));
				start=intervals[i].start;
				end=intervals[i].end;
			}
			else
				end=end>intervals[i].end?end:intervals[i].end;
		}
		if(res.empty()||start!=res.back().start)
			res.push_back(Interval(start,end));
		
		return res;
    }
};
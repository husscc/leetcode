/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int startpos,endpos;
    	bool startin=false,endin=false;
		vector<Interval> res;
		if(intervals.size()==0){
            res.push_back(newInterval);
			return res;
		}
		
		for(startpos=0;startpos<intervals.size();startpos++){
			if(newInterval.start<intervals[startpos].start)
				break;
			else if(intervals[startpos].start<=newInterval.start&&newInterval.start<=intervals[startpos].end){
				startin=true;
				break;
			}
		}
		
		if(startpos==intervals.size()){
			res=intervals;
			res.push_back(newInterval);
			return res;
		}
		else{
			for(endpos=startpos;endpos<intervals.size();endpos++){
				if(intervals[endpos].start<=newInterval.end&&newInterval.end<=intervals[endpos].end){
					endin=true;
					break;
				}
				else if(intervals[endpos].start>newInterval.end)
					break;
			}
			
		}
		
		int i;
		for(i=0;i<startpos;i++)
			res.push_back(intervals[i]);
				//we need to merge two subsequence
		Interval intl;
		if(startin)
			intl.start=intervals[startpos].start;
		else
			intl.start=newInterval.start;
			
		if(endin)
			intl.end=intervals[endpos].end;
		else
			intl.end=newInterval.end;
				
		res.push_back(intl);
		
		
		if(endin)
			i=endpos+1;
		else
			i=endpos;
        
		for(;i<intervals.size();i++)
			res.push_back(intervals[i]);
		
		return res;
    }
};
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(2,-1);
    	
		if(!n||target<A[0]||target>A[n-1])
			return res;
		
		int start=0,end=n-1,mid;
		
		//binary search the target
		while(start<=end){
			mid=(start+end)/2;
			if(A[mid]==target)
				break;
			else if(A[mid]<target)
				start=mid+1;
			else					//A[mid]>target
				end=mid-1;
		}
		
		if(A[mid]!=target)
			return res;
		
		int p;
		//try to find the start position
		if(A[start]==target||start==mid)
			res[0]=start;
		else{			//if(start<mid)
			int end_mirror=mid;
			while(1){
				p=(start+end_mirror)/2+1;
				if(A[p]==target&&A[p-1]!=target){
					res[0]=p;
					break;
				}
				else if(A[p]==target&&A[p-1]==target)
					end_mirror=p-1;
				else
					start=p;;
			}
		}
			
		//try to find the end position
		if(A[end]==target||end==mid)
			res[1]=end;
		else{			//if(mid<end)
			while(1){
				p=(mid+end)/2;
				if(A[p]==target&&A[p+1]!=target){
					res[1]=p;
					break;
				}
				else if(A[p]==target&&A[p+1]==target)
					mid=p+1;
				else
					end=p;
			}
		}
		return res;
    }
};
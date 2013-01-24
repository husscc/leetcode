/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/
class Solution {
    int binarySearch(int A[],int start,int end,int target){
		if(target<=A[start])
			return start;
		else if(A[end]<target)
			return end+1;
		else{
			int mid=(start+end)/2;
			if(A[mid]==target)
				return mid;
			else if(A[mid]<target)
				return binarySearch(A,mid+1,end,target);
			else
				return binarySearch(A,start,mid-1,target);
		}
	}
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n>0)
			return binarySearch(A,0,n-1,target);
		else
			return 0;
    }
};
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int start=0,end=n-1,mid=(start+end)/2;
		while(start<=end){
			if(A[mid]==target)
				return mid;
			else if(start==end&&A[start]!=target)
				break;
			else if(A[mid]<target){				//That's the normal sorted array
				if(A[start]<A[end]
					||(A[mid]<A[end]&&target<=A[end])
					||A[start]<A[mid]
					){
					start=mid+1;
					mid=(start+end)/2;
				}
				else{
					end=mid-1;
					mid=(start+end)/2;
				}
			}
			else{								//That's the normal sorted array
				if(A[start]<A[end]
					||(A[start]<A[mid]&&A[start]<=target)
					||A[mid]<A[end]
					){
					end=mid-1;
					mid=(start+end)/2;
				}
				else{
					start=mid+1;
					mid=(start+end)/2;
				}
			}
		}
		
		return -1;
    }
};

/*
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<n;i++){
            if(A[i]==target)
                return i;
        }
        return -1;
    }
};
*/
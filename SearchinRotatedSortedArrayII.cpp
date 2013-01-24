/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
    bool binarySearch(int A[],int start,int end,int target){
		int mid=(start+end)/2;
		
		if(A[end]==target||A[start]==target||A[mid]==target)
			return true;
			
		else if(end-start<3)
			return false;
		
		else{
			if(A[mid]<target){
				if(	
					A[start]<A[end]
					||(target<A[end]&&A[mid]<A[end])
					||(A[start]<A[mid])
				)
					return binarySearch(A,mid+1,end,target);
				else if(A[mid]<A[end]&&A[end]<target)
					return binarySearch(A,start,mid-1,target);
				else
					return binarySearch(A,start,mid-1,target)||binarySearch(A,mid+1,end,target);
			}
			else{			//A[mid]>target
				if(
					A[start]<A[end]
					||(A[start]<A[mid]&&A[start]<target)
					||(A[mid]<A[end])
				)
					return binarySearch(A,start,mid-1,target);
				else if(target<A[start]&&A[start]<A[mid])
					return binarySearch(A,mid+1,end,target);
				else
					return binarySearch(A,start,mid-1,target)||binarySearch(A,mid+1,end,target);
			}
		}
	}

	
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!n)
			return false;
		return binarySearch(A,0,n-1,target);
    }
};


/*
class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<n;i++){
            if(A[i]==target)
                return 1;
        }
        return 0;
    }
};
*/

/*
    void findmin(int A[],int start,int end,int &index){
    	
		if(A[start]<A[end]||start==end){
			index=A[start]<A[index]?start:index;
		}
        else if(start+1==end){
			if(A[start]>A[end])
				index=end;
			else
				index=A[start]<A[index]?start:index;
        }
		else{
			int mid=(start+end)/2;
			if(A[mid]>A[end]){
				if(A[mid]>A[mid+1])
                    index=mid+1;
                else
					findmin(A,mid+1,end,index); 
				
			}
			else if(A[start]>A[mid]){
				if(A[mid-1]>A[mid])
					index=mid;
				else
					findmin(A,start,mid-1,index);
			}
            else{
                findmin(A,start,mid-1,index);
                findmin(A,mid+1,end,index);
            }
		}
		return;
	}
*/
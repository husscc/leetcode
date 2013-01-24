/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/
class Solution {
    int findKth(int A[],int m,int B[],int n,int k){
		if(m==0)
			return B[k-1];
		else if(n==0)
			return A[k-1];
		
		if(k==1)
			return min(A[0],B[0]);
		
		int pA=(m*k/(m+n))>0?(m*k/(m+n)):1,pB=k-pA;    			//m : n = a : (k-a)

		if(A[pA-1]==B[pB-1])
			return A[pA-1];	
		else if(A[pA-1]>B[pB-1])
			return findKth(A,pA,B+pB,n-pB,k-pB);
		else
			return findKth(A+pA,m-pA,B,pB,k-pA);
	}
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total=m+n;
		
		if(total==0)
			return 0;
		else if(total&0x1)
			return findKth(A,m,B,n,total/2+1);
		else
			return (findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2.0;
    }
};
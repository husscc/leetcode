/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0)
        	return;
		else if(m==0){
			memcpy(A,B,n*sizeof(int));
			return;
		}
		
		int pA=0,pB=0,len_m=m;
		
		while(pA<len_m&&pB<n){
			if(A[pA]<=B[pB])
				pA++;
			else{
				int count=0;
				while(pB<n&&A[pA]>B[pB]){
					count++; pB++;
				}
				//memcpy(A+pA+count,A+pA,(len_m-pA)*sizeof(int));
                for(int i=len_m-pA-1;i>=0;i--)
                    A[pA+count+i]=A[pA+i];
				memcpy(A+pA,B+pB-count,count*sizeof(int));
                pA+=count;
                len_m+=count;
			}
		}
		
		if(pA==len_m&&pB<n)
			memcpy(A+pA,B+pB,(n-pB)*sizeof(int));
		
		return;
    }
};
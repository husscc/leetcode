/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *flag=(char*)malloc(sizeof(char)*n);
    	memset(flag,0x0,sizeof(char)*n);
		flag[0]=0x1;
		
		if(n<2)
			return true;
		
		for(int i=0;i<n;i++){
			if(flag[i]==0x0)
				return false;
			if(A[i]+i>=n-1)
				return true;
            if(A[i]>0)
                memset(&flag[i+1],0x1,sizeof(char)*A[i]);
		}
    }
};
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<2)
            return 0;
        unsigned int* jcount=(unsigned int*)malloc(sizeof(unsigned int)*n);
    	memset(jcount,n,sizeof(unsigned int)*n);
		jcount[0]=0;
		int jc;
		for(int i=0;i<n;i++){
			if(i+A[i]>=n-1)
				return jcount[i]+1;
            jc=jcount[i]+1;
			for(int j=A[i]+i;jc<jcount[j]&&j>i;j--){
				jcount[j]=jc;
			}
		}
		return jcount[n-1];
    }
};
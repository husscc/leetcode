/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!n)
			return 0;
        int len=0,count=1;
		for(int i=0;i<n;i++){
			if(A[len]!=A[i]){
				swap(A[++len],A[i]);
				count=1;
			}
			else if(count<2&&len!=i){
				swap(A[++len],A[i]);
				count++;
			}
		}
		return len+1;
    }
};